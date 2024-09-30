#include <vlc/vlc.h>
#include <iostream>
#include <unistd.h>


#include "ressources-loading/audio-player.h"

void AudioPlayer::set_song(std::string filepath){

	_is_seeking= false;

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

bool AudioPlayer::is_seeking(){
	return _is_seeking;
}


void AudioPlayer::play(){
	libvlc_media_player_play(_media_player);
}

void AudioPlayer::pause(){
	libvlc_media_player_pause(_media_player);
	_is_paused = true;
	_seeked_position = ((double)libvlc_media_player_get_time(_media_player)) / 1000.0;
}

void AudioPlayer::stop(){
	libvlc_media_player_stop_async(_media_player);
}

double AudioPlayer::get_duration(){
	return ((double)libvlc_media_player_get_length(_media_player)) / 1000.0;
}



double AudioPlayer::get_position(){
	if (_is_paused)
		return _seeked_position;

	if(_is_seeking){
		if (is_playing())
			_is_seeking = false;
		else
			libvlc_media_player_play(_media_player);
	}

	if(!_is_seeking)
		return ((double)libvlc_media_player_get_time(_media_player)) / 1000.0;
	return _seeked_position;
}

void AudioPlayer::set_position(double pos){
	_is_seeking = true;
	_is_paused = false;
	_seeked_position = pos;
	libvlc_media_player_pause(_media_player);
	libvlc_media_player_set_time(_media_player, (int)pos * 1000, false);
	libvlc_media_player_play(_media_player);
}


AudioPlayer::AudioPlayer(/* args */)
{
	_is_seeking = false;
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

