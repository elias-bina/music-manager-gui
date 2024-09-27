#ifndef MMG_UI_WIDGETS_SONG_LIST
#define MMG_UI_WIDGETS_SONG_LIST

class SongWidgetList;

#include <memory>
#include <vector>

#include "ressources-loading/texture-load.h"

#include "ui/widgets/current-song.h"
#include "ui/widgets/song.h"
#include "ui/widgets/widget.h"

class SongWidgetList : RenderableWidget, SongObserver
{
private:
	LoadedTexture _download_icon;
	LoadedTexture _valid_icon;

public:
	CurrentSongWidget* _current_song = NULL;

	SongWidgetList();

	std::vector<std::shared_ptr<SongWidget>> _song_list;
	void Render();

	void AddSong(std::string song_name, std::string song_link);
	void DeselectAllSongs();

	void songUpdateNotify(std::shared_ptr<SongWidget> chosen_song);
};

#endif