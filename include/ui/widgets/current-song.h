#ifndef MMG_UI_WIDGETS_CURRENT_SONG
#define MMG_UI_WIDGETS_CURRENT_SONG

#include <memory>
#include <vector>

#include "ui/widgets/widget.h"
#include "ui/widgets/song.h"

class CurrentSongWidget : RenderableWidget
{
private:
	LoadedTexture _play_texture;

	std::shared_ptr<SongWidget> _current_song = nullptr;
public:
	CurrentSongWidget();

	void Render();

	void SetSong(std::shared_ptr<SongWidget> song);
};

#endif