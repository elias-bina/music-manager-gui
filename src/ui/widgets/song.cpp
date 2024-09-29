#include <stdio.h>
#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#include <io.h>
#define F_OK 0
#define access _access
#else
#include <unistd.h>
#endif



#include "imgui/imgui.h"

#include "ressources-loading/texture-load.h"
#include "ressources-loading/download-management.h"
#include "ui/widgets/song.h"



SongWidget::SongWidget(std::string name, std::string link, LoadedTexture* download_texture, LoadedTexture* valid_texture, LoadedTexture* delete_texture): _download_texture{download_texture}, _valid_texture{valid_texture}, _delete_texture{delete_texture}, _name{name}, _link{link}, _is_selected{false}, _should_update{0}
{
	_downloaded = (access(("downloaded_songs/" + name + ".mp3").c_str(), F_OK) == 0);
}

SongWidget::~SongWidget()
{
}

void SongWidget::Render(){
	// TODO: Add tooltip
	
	ImGui::AlignTextToFramePadding();
	
	ImGui::SetNextItemAllowOverlap();
	if(ImGui::Selectable(("##" +  _name).c_str() , _is_selected, 0, ImVec2(0,21))){
		_should_update = true;
	}
	// ImGui::Spacing();
	ImGui::SameLine();

	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 3);

	ImGui::Text("%s", _name.c_str());
	
	ImGui::SameLine();



	if(!_downloaded){
	
		int spacing = 10;
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - (float)_download_texture->width - (float)spacing);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);

		// ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(-1.0f,- 1.0f));
		if(ImGui::ImageButton(("##Button" +  _name).c_str(),(void*)(intptr_t)_download_texture->texture, ImVec2( (float)_download_texture->width,  (float)_download_texture->height))){
			
			_downloaded = true;
			
			printf("%s", ("TELECHARGE " + _link + " BATARD\n").c_str());

			basic_youtube_audio_download(_name, _link);
		}

		// ImGui::PopStyleVar();
	} else {

		

		int spacing = 10 + 16 + 16;
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - (float)_download_texture->width - (float)spacing + 4);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);

		if(ImGui::ImageButton(("##RemoveButton" +  _name).c_str(),(void*)(intptr_t)_delete_texture->texture, ImVec2( (float)_delete_texture->width,  (float)_delete_texture->height))){
			
			remove(("downloaded_songs/" + _name + ".mp3").c_str());
			_downloaded = false;
		}

		ImGui::SameLine();

		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

		ImGui::Image((void*)(intptr_t)_valid_texture->texture, ImVec2( (float)_valid_texture->width,  (float)_valid_texture->height), ImVec2(0, 0), ImVec2(1, 1), ImVec4(1, 1, 1, 1), ImVec4(0, 0, 0, 0));
	}

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

std::string SongWidget::getLink(){
	return _link;
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

bool SongWidget::isDownloaded(){
	return _downloaded;
}


void SongWidget::addObserver(SongObserver* observer){
	_list_observers.push_back(observer);
}

void SongWidget::notifyObservers(std::shared_ptr<SongWidget> song){
	for(SongObserver* observer: _list_observers){
		observer->songUpdateNotify(song);
	}
}