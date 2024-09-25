#include "imgui/imgui.h"

#include "ressources_loading/texture_load.h"
#include "ui/widgets/song.h"



SongWidget::SongWidget(std::string name, LoadedTexture* texture): _texture{texture}, _name{name}
{
}

void SongWidget::Render(){
	// TODO: Add tooltip
	ImGui::Text(_name.c_str());
	ImGui::SameLine();

	ImGuiIO io = ImGui::GetIO();

	ImGui::Image((void*)(intptr_t)_texture->texture, ImVec2(_texture->width, _texture->height));

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

SongWidget::~SongWidget()
{
}