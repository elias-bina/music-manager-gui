#include "math.h"

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
			if(_audio_player.is_playing() || _audio_player.is_seeking()){				
				if(ImGui::ImageButton(("##PauseButton" +  _current_song->getName()).c_str(),(void*)(intptr_t)_stop_texture.texture, ImVec2( (float)_stop_texture.width / 2,  (float)_stop_texture.height / 2)))
				{
					_audio_player.pause();
				}
			}
			else{
				if(ImGui::ImageButton(("##PlayButton" +  _current_song->getName()).c_str(),(void*)(intptr_t)_play_texture.texture, ImVec2( (float)_play_texture.width / 2,  (float)_play_texture.height / 2))){
					_audio_player.play();
				}
			}

			ImGui::SameLine();

			ImGui::BeginGroup();

			double curr_position = _audio_player.get_position();
			double curr_duration = _audio_player.get_duration();
			float curr_position_ratio = (float)(curr_position / curr_duration);
			float prev_position_ratio = curr_position_ratio;

			int size = snprintf(NULL, 0,"%s / %s", hms_display( _audio_player.get_position()).c_str(), hms_display(_audio_player.get_duration()).c_str()) + 1;
			char* fmt = (char*)malloc(sizeof(char) * size + 1);

			snprintf(fmt, size, "%s / %s", hms_display( _audio_player.get_position()).c_str(), hms_display(_audio_player.get_duration()).c_str());

			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 1);
			ImGui::SliderFloat(("##Slider" +  _current_song->getName()).c_str(), &curr_position_ratio, 0, 1, fmt, ImGuiSliderFlags_None);
			ImGui::PopItemWidth();

			if(fabs(prev_position_ratio - curr_position_ratio) > 0.0001){
				_audio_player.set_position(curr_position_ratio * curr_duration);
			}

			free(fmt);

			ImGui::EndGroup();

		}
	}
}

void CurrentSongWidget::SetSong(std::shared_ptr<SongWidget> song){
	_current_song = song;
	_audio_player.set_song(_current_song->getName());
}