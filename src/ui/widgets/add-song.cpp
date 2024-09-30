#include "imgui/imgui.h"

#include "ui/widgets/add-song.h"

#include <stdio.h>


AddSongWidget::AddSongWidget(add_song_callback_t add_song_callback, void* user_param): _add_song_callback{add_song_callback}, _user_param{user_param}
{

}


AddSongWidget::~AddSongWidget()
{

}

void AddSongWidget::Render(){

	ImGui::BeginGroup();

	ImGui::Text("Title of song");
	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
	ImGui::InputText("##song_name", _song_name, IM_ARRAYSIZE(_song_name));

	ImGui::Text("Link of song");
	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
	ImGui::InputText("##song_link", _song_link, IM_ARRAYSIZE(_song_link));

	if(ImGui::Button("Add Song")){
		AddSong(_song_name, _song_link);
		_added_message = std::string(_song_name) + " added to the songlist !" ;
		_added_message_timer = NB_FRAME_ADDED_SONG_MESSAGE;
		*_song_name = '\0';
		*_song_link = '\0';
	}

	if(_added_message_timer > 0){
		_added_message_timer--;
		ImGui::Text("%s", _added_message.c_str());
	}



	ImGui::EndGroup();

}

void AddSongWidget::AddSong(std::string name, std::string link){
	_add_song_callback(_user_param, name, link);
}

