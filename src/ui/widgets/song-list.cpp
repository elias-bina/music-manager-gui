#include <memory>
#include "imgui/imgui.h"


#include "ui/widgets/song-list.h"

SongWidgetList::SongWidgetList()
{
	bool ret = LoadTextureFromFile("ressources/DownloadIconWhite.png", &_download_icon);
	IM_ASSERT(ret);
}

void SongWidgetList::Render(){

	ImGui::BeginChild("SongListShown", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, ImGui::GetContentRegionAvail().y), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);

	for(std::shared_ptr<SongWidget> song: _song_list){
		song->Render();
		if(song->isSelected()){
			_current_song = song;
		}
	}

	ImGui::EndChild();

}

void SongWidgetList::AddSong(std::string song_name){
	_song_list.push_back(std::make_shared<SongWidget>(song_name, &_download_icon, this));
}

void SongWidgetList::DeselectAllSongs(){
	for(std::shared_ptr<SongWidget> song: _song_list)
		song->deselect();
}

