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

#include "ressources_loading/texture_load.h"
#include "ui/widgets/song.h"



SongWidget::SongWidget(std::string name, std::string link, LoadedTexture* texture): _texture{texture}, _name{name}, _link{link}, _is_selected{false}, _should_update{0}
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
	if(ImGui::Selectable(("##" +  _name).c_str() , _is_selected, 0, ImVec2(0,20))){
		_should_update = true;
	}
	// ImGui::Spacing();
	ImGui::SameLine();

	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);

	ImGui::Text("%s", _name.c_str());
	
	if(!_downloaded){
	
		ImGui::SameLine();

		int spacing = 10;
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - (float)_texture->width - (float)spacing);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2);
		// ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(-1.0f,- 1.0f));
		if(ImGui::ImageButton(("##Button" +  _name).c_str(),(void*)(intptr_t)_texture->texture, ImVec2( (float)_texture->width,  (float)_texture->height))){
			
			_downloaded = true;
			
			printf("%s", ("TELECHARGE " + _link + " BATARD\n").c_str());

			// TODO: Download manager


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			STARTUPINFO si;
			PROCESS_INFORMATION pi;

			ZeroMemory( &si, sizeof(si) );
			si.cb = sizeof(si);
			ZeroMemory( &pi, sizeof(pi) );

			char* cmdline = strdup(("./dependencies/yt-dlp/yt-dlp.sh " + _link + "-x --audio-format mp3 -o " + "downloaded_songs/" + _name).c_str());
			// Start the child process. 
			if( !CreateProcessA( NULL,   // No module name (use command line)
				cmdline,        // Command line
				NULL,           // Process handle not inheritable
				NULL,           // Thread handle not inheritable
				FALSE,          // Set handle inheritance to FALSE
				0,              // No creation flags
				NULL,           // Use parent's environment block
				NULL,           // Use parent's starting directory 
				&si,            // Pointer to STARTUPINFO structure
				&pi )           // Pointer to PROCESS_INFORMATION structure
			) 
			{
				printf( "CreateProcess failed (%d).\n", (int)GetLastError() );
				return;
			}
#else
			if (fork() == 0) {
			/*
			* fork() returns 0 to the child process
			* and the child's PID to the parent.
			*/
			execl("./dependencies/yt-dlp/yt-dlp.sh", "yt-dlp.sh", _link.c_str(), "-x", "--audio-format", "mp3", "-o", ("downloaded_songs/" + _name).c_str(), 0);
			//   execl("./dependencies/yt-dlp/yt-dlp.sh", "yt-dlp.sh", _link.c_str(), "-x", "--audio-format", "mp3", "-o", ("downloaded_songs/" + _name).c_str(), "-q", 0);
			/*
			* We wouldn't still be here if execl() was successful,
			* so a non-zero exit value is appropriate.
			*/
			exit(1);
			}
#endif
		}
		// ImGui::PopStyleVar();
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