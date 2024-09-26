#include "imgui/imgui.h"

#include "ui/widgets/current-song.h"

CurrentSongWidget::CurrentSongWidget(){

}

void CurrentSongWidget::Render(){
	if(_current_song == NULL){
		ImGui::Text("No song selected");
	} else	{
		ImGui::Text(_current_song->getName().c_str());
	}
}

void CurrentSongWidget::SetSong(std::shared_ptr<SongWidget> song){
	_current_song = song;
}