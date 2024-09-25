#ifndef MMG_UI_WIDGETS_SONG
#define MMG_UI_WIDGETS_SONG

#include <string>

#include "widget.h"
#include "GLFW/glfw3.h"

#include "ressources_loading/texture_load.h"

class SongWidget : RenderableWidget
{
private:
	LoadedTexture* _texture;
	std::string _name;
public:
	SongWidget(std::string name,LoadedTexture* texture);
	~SongWidget();

	void Render();
};

#endif