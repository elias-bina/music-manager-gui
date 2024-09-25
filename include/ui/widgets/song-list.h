#ifndef MMG_UI_WIDGETS_SONG_LIST
#define MMG_UI_WIDGETS_SONG_LIST

#include <vector>

#include "ressources_loading/texture_load.h"

#include "widget.h"
#include "song.h"

class SongWidgetList : RenderableWidget
{
private:
	LoadedTexture _download_icon;
public:
	SongWidgetList();

	std::vector<SongWidget> _song_list;
	void Render();

	void AddSong(std::string song_name);
};

#endif