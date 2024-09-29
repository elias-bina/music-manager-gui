#include <vlc/vlc.h>
#include <iostream>
#include <unistd.h>


#include "ressources-loading/audio-player.h"

void AudioPlayer::set_song(std::string filepath){

	if(_media_player != NULL){
		stop();
		libvlc_media_player_release(_media_player);
		_media_player = NULL;
	}
	if(_current_loaded_media != NULL){
		libvlc_media_release(_current_loaded_media);
		_current_loaded_media = NULL;
	}

	_song_filepath = "downloaded_songs/"  + filepath + ".mp3";

    _current_loaded_media = libvlc_media_new_path(_song_filepath.c_str());
    if (!_current_loaded_media) {
        std::cerr << "Erreur : impossible de charger le fichier média." << std::endl;
        return;
    }

    _media_player = libvlc_media_player_new_from_media(_libvlc_instance, _current_loaded_media);
    if (!_media_player) {
        std::cerr << "Erreur : impossible de créer le lecteur multimédia." << std::endl;
        libvlc_media_release(_current_loaded_media);
        return;
    }
}

bool AudioPlayer::is_playing(){
	return libvlc_media_player_is_playing(_media_player);
}

void AudioPlayer::play(){
	libvlc_media_player_play(_media_player);
}

void AudioPlayer::stop(){
	libvlc_media_player_stop_async(_media_player);
}

double AudioPlayer::get_duration(){
	return ((double)libvlc_media_player_get_length(_media_player)) / 1000.0;
}

double AudioPlayer::get_position(){
	return ((double)libvlc_media_player_get_time(_media_player)) / 1000.0;
}


AudioPlayer::AudioPlayer(/* args */)
{
	 // Create a new libVLC instance
	if (!_libvlc_instance) {
	_libvlc_instance = libvlc_new(0, nullptr);
		std::cerr << "Erreur : impossible d'initialiser libVLC." << std::endl;
		return;
	}
}


AudioPlayer::~AudioPlayer()
{
	libvlc_release(_libvlc_instance);
}

