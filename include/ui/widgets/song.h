#ifndef MMG_UI_WIDGETS_SONG
#define MMG_UI_WIDGETS_SONG

class SongWidget;

#include <string>
#include <memory>
#include <vector>

#include "widget.h"
#include "GLFW/glfw3.h"

#include "ressources_loading/texture_load.h"
#include "ui/widgets/song-observer.h"

class SongWidget : RenderableWidget
{
private:
	LoadedTexture* _texture;
	std::string _name;
	bool _is_selected;
	bool _should_update;

	std::vector<SongObserver*> _list_observers;

public:
	SongWidget(std::string name, LoadedTexture* texture);
	~SongWidget();

	void Render();
	void Update(std::shared_ptr<SongWidget> song);

	std::string getName();
	bool isSelected();
	void deselect();
	void select();

	void addObserver(SongObserver* observer);
	void notifyObservers(std::shared_ptr<SongWidget> song);
};

#endif