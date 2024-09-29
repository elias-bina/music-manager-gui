#ifndef MMG_UI_WIDGETS_SONG
#define MMG_UI_WIDGETS_SONG

class SongWidget;

#include <string>
#include <memory>
#include <vector>

#include "widget.h"
#include "GLFW/glfw3.h"

#include "ressources-loading/texture-load.h"
#include "ui/widgets/song-observer.h"

class SongWidget : RenderableWidget
{
private:
	LoadedTexture* _download_texture;
	LoadedTexture* _valid_texture;
	LoadedTexture* _delete_texture;
	std::string _name;
	std::string _link;
	bool _downloaded;

	// TODO: Most liked moments in the song

	bool _is_selected;
	bool _should_update;

	std::vector<SongObserver*> _list_observers;

public:
	SongWidget(std::string name, std::string link, LoadedTexture* download_texture, LoadedTexture* valid_texture, LoadedTexture* delete_texture);
	~SongWidget();

	void Render();
	void Update(std::shared_ptr<SongWidget> song);

	std::string getName();
	bool isSelected();
	void deselect();
	void select();

	bool isDownloaded();

	void addObserver(SongObserver* observer);
	void notifyObservers(std::shared_ptr<SongWidget> song);
};

#endif