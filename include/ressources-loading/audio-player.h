#ifndef MMG_UI_RESSOURCE_LOADING_AUDIO_PLAYER
#define MMG_UI_RESSOURCE_LOADING_AUDIO_PLAYER

#include <vlc/vlc.h>
#include <string>

class AudioPlayer
{
private:
	std::string _song_filepath;
	libvlc_instance_t* _libvlc_instance = NULL;
	libvlc_media_t* _current_loaded_media = NULL;
	libvlc_media_player_t* _media_player = NULL;

	bool _is_seeking = false;
	bool _is_paused = false;
	double _seeked_position;
public:

	void set_song(std::string filepath);

	bool is_playing();
	bool is_seeking();

	void play();
	void pause();
	void stop();

	double get_duration();
	double get_position();
	
	void set_position(double pos);

	AudioPlayer(/* args */);
	~AudioPlayer();
};




#endif