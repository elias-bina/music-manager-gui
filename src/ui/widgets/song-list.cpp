#include "imgui/imgui.h"


#include "ui/widgets/song-list.h"

SongWidgetList::SongWidgetList()
{
	bool ret = LoadTextureFromFile("ressources/DownloadIconWhite.png", &_download_icon);
	IM_ASSERT(ret);
}

void SongWidgetList::Render(){

	for(long unsigned int i = 0; i < _song_list.size(); i++){
		_song_list[i].Render();
	}

}

void SongWidgetList::AddSong(std::string song_name){
	_song_list.push_back(SongWidget(song_name, &_download_icon));
}
