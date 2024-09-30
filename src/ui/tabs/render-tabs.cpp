#include "imgui/imgui.h"

#include "ui/tabs/render-tabs.h"

void RenderTabsManagement(AppContext &context)
{
	ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_Reorderable;
	if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
	{
		if (ImGui::BeginTabItem("List all Songs"))
		{
			context._songWidgets.Render();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Search"))
		{
			ImGui::Text("Froggy ! Where are you ?\nI will search ans sort songs here");
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Add Song"))
		{
			context._addSongWidget.Render();
			ImGui::EndTabItem();
		}

		ImGui::BeginDisabled();
		if (ImGui::BeginTabItem("Modify Song"))
		{
			ImGui::Text("U wrong\nI will modify songs here (Should be clickable only if I have a song selected)");
			ImGui::EndTabItem();
		}
		ImGui::EndDisabled();

		ImGui::EndTabBar();
	
	}
}
