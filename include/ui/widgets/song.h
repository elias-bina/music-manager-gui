#ifndef MMG_UI_WIDGETS_SONG
#define MMG_UI_WIDGETS_SONG

#include "widget.h"
#include "GLFW/glfw3.h"

class SongWidget : RenderableWidget
{
private:
	int my_image_width = 0;
	int my_image_height = 0;
	GLuint my_image_texture = 0;
public:
	SongWidget(/* args */);
	~SongWidget();

	void Render();
};

#endif