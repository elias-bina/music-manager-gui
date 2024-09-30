#ifndef MMG_UI_WIDGETS_ADD_SONG
#define MMG_UI_WIDGETS_ADD_SONG

#include "ui/widgets/song.h"
#include "ui/widgets/widget.h"

typedef void (*add_song_callback_t)(void* user_param, std::string name, std::string link);

constexpr int NB_FRAME_ADDED_SONG_MESSAGE = 100;

class AddSongWidget: public RenderableWidget
{
private:
	void (* _add_song_callback) (void* user_param, std::string name, std::string link) = nullptr;
	void* _user_param = nullptr;

	char _song_name[64] = "";
	char _song_link[64] = "";

	std::string _added_message = "";
	int _added_message_timer = 0;

public:
	AddSongWidget(add_song_callback_t add_song_callback, void* user_param);
	~AddSongWidget();

	void Render();
	void AddSong(std::string name, std::string link);

};

#endif