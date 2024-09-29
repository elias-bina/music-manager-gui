#include "imgui/imgui.h"

#include "ressources-loading/audio-player.h"

#include "ui/utils/hms-display.h"
#include "ui/widgets/current-song.h"

CurrentSongWidget::CurrentSongWidget(): _current_song{nullptr}
{
	bool ret = LoadTextureFromFile("ressources/PlayIconWhite.png", &_play_texture);
	IM_ASSERT(ret);
	ret = LoadTextureFromFile("ressources/StopIconColor.png", &_stop_texture);
	IM_ASSERT(ret);
}

void CurrentSongWidget::Render(){
	if(_current_song == nullptr){
		ImGui::Text("No song selected");
	} else	{

		ImGui::Text("%s",_current_song->getName().c_str());

		if (_current_song->isDownloaded()){
			if(_audio_player.is_playing()){
				if(ImGui::ImageButton(("##PauseButton" +  _current_song->getName()).c_str(),(void*)(intptr_t)_stop_texture.texture, ImVec2( (float)_stop_texture.width / 2,  (float)_stop_texture.height / 2)))
				{
					_audio_player.stop();
				}
			}
			else{
				if(ImGui::ImageButton(("##PlayButton" +  _current_song->getName()).c_str(),(void*)(intptr_t)_play_texture.texture, ImVec2( (float)_play_texture.width / 2,  (float)_play_texture.height / 2))){
					_audio_player.play();
				}
			}

			ImGui::SameLine();

			ImGui::Text("%s / %s", hms_display(_audio_player.get_position()).c_str(), hms_display(_audio_player.get_duration()).c_str());

		}
	}
}

void CurrentSongWidget::SetSong(std::shared_ptr<SongWidget> song){
	_current_song = song;
	_audio_player.set_song(_current_song->getName());
}