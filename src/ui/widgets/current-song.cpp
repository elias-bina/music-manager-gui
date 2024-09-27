#include "imgui/imgui.h"

#include "ui/widgets/current-song.h"


CurrentSongWidget::CurrentSongWidget(): _current_song{nullptr}
{
	bool ret = LoadTextureFromFile("ressources/ValidIconWhite.png", &_play_texture);
	IM_ASSERT(ret);
}

void CurrentSongWidget::Render(){
	if(_current_song == nullptr){
		ImGui::Text("No song selected");
	} else	{

		ImGui::Text("%s",_current_song->getName().c_str());

		if (_current_song->isDownloaded()){
			if(ImGui::ImageButton(("##PlayButton" +  _current_song->getName()).c_str(),(void*)(intptr_t)_play_texture.texture, ImVec2( (float)_play_texture.width,  (float)_play_texture.height))){
			

			}
		}
	}
}

void CurrentSongWidget::SetSong(std::shared_ptr<SongWidget> song){
	_current_song = song;
}