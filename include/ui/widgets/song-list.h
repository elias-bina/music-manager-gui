#ifndef MMG_UI_WIDGETS_SONG_LIST
#define MMG_UI_WIDGETS_SONG_LIST

class SongWidgetList;

#include <memory>
#include <vector>

#include "ressources_loading/texture_load.h"

#include "widget.h"
#include "song.h"

class SongWidgetList : RenderableWidget
{
private:
	LoadedTexture _download_icon;
	std::shared_ptr<SongWidget> _current_song = NULL;
public:
	SongWidgetList();

	std::vector<std::shared_ptr<SongWidget>> _song_list;
	void Render();

	void AddSong(std::string song_name);
	void DeselectAllSongs();
};

#endif