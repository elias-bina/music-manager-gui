#ifndef MMG_UI_WIDGETS_SONG
#define MMG_UI_WIDGETS_SONG

class SongWidget;

#include <string>

#include "widget.h"
#include "GLFW/glfw3.h"

#include "ressources_loading/texture_load.h"
#include "ui/widgets/song-list.h"


class SongWidget : RenderableWidget
{
private:
	LoadedTexture* _texture;
	std::string _name;
	bool _is_selected;
	SongWidgetList* _list_songs;

public:
	SongWidget(std::string name, LoadedTexture* texture, SongWidgetList* _list_songs);
	~SongWidget();

	void Render();
	std::string getName();
	bool isSelected();
	void deselect();

};

#endif