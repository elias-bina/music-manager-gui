#include <iostream>
#include <unistd.h>

#include "imgui/imgui.h"

#include "ressources_loading/texture_load.h"
#include "ui/widgets/song.h"



SongWidget::SongWidget(std::string name, std::string link, LoadedTexture* texture): _texture{texture}, _name{name}, _link{link}, _is_selected{false}
{
}

SongWidget::~SongWidget()
{
}

void SongWidget::Render(){
	// TODO: Add tooltip
	
	ImGui::AlignTextToFramePadding();
	
	ImGui::SetNextItemAllowOverlap();
	if(ImGui::Selectable(("##" +  _name).c_str() , _is_selected, 0, ImVec2(0,20))){
		_should_update = true;
	}
	// ImGui::Spacing();
	ImGui::SameLine();

	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);

	ImGui::Text(_name.c_str());
	ImGui::SameLine();


	int spacing = 10;
	ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - _texture->width - spacing);
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);
	// ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(-1.0f,- 1.0f));
	if(ImGui::ImageButton(("##Button" +  _name).c_str(),(void*)(intptr_t)_texture->texture, ImVec2(_texture->width, _texture->height))){
		printf(("TELECHARGE " + _link + " BATARD\n").c_str());
		if (fork() == 0) {
          /*
           * fork() returns 0 to the child process
           * and the child's PID to the parent.
           */
          execl("./dependencies/yt-dlp/yt-dlp.sh", "yt-dlp.sh", _link.c_str(), "-x", "--audio-format", "mp3", "-o", ("downloaded_songs/" + _name).c_str(), 0);
          /*
           * We wouldn't still be here if execl() was successful,
           * so a non-zero exit value is appropriate.
           */
          exit(1);
     	}
	}
	// ImGui::PopStyleVar();



	// ImGuiIO io = ImGui::GetIO();
	// ImTextureID my_tex_id = io.Fonts->TexID;
	// float my_tex_w = (float)io.Fonts->TexWidth;
	// float my_tex_h = (float)io.Fonts->TexHeight;
	// ImVec2 pos = ImGui::GetCursorScreenPos();
	// ImVec2 uv_min = ImVec2(0.0f, 0.0f);                 // Top-left
	// ImVec2 uv_max = ImVec2(1.0f, 1.0f);                 // Lower-right
	// ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // No tint
	// ImVec4 border_col = ImGui::GetStyleColorVec4(ImGuiCol_Border);
	// ImGui::Image(my_tex_id, ImVec2(my_tex_w, my_tex_h), uv_min, uv_max, tint_col, border_col);

}

void  SongWidget::Update(std::shared_ptr<SongWidget> song){
	if(_should_update){
		notifyObservers(song);
		_should_update = false;
	}
}



std::string SongWidget::getName(){
	return _name;
}

bool SongWidget::isSelected(){
	return _is_selected;
}

void SongWidget::deselect(){
	_is_selected = false;
}

void SongWidget::select(){
	_is_selected = true;
}

void SongWidget::addObserver(SongObserver* observer){
	_list_observers.push_back(observer);
}

void SongWidget::notifyObservers(std::shared_ptr<SongWidget> song){
	for(SongObserver* observer: _list_observers){
		observer->songUpdateNotify(song);
	}
}