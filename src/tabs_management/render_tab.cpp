#include "imgui.h"

#include "tabs_management/render_tab.h"

void RenderTabsManagement(AppContext &context)
{
	ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
	if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
	{
		if (ImGui::BeginTabItem("List all Songs"))
		{
			ImGui::Text("Hehe, secret Song\nI will see all songs here");
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Search"))
		{
			ImGui::Text("Froggy ! Where are you ?\nI will search ans sort songs here");
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Add Song"))
		{
			ImGui::Text("Poyo <3\nI will add new songs here");
			ImGui::EndTabItem();
		}

		ImGui::BeginDisabled();
		if (ImGui::BeginTabItem("Modify Song (Name modifiable here ?)"))
		{
			ImGui::Text("U wrong\nI will modify songs here (Should be clickable only if I have a song selected)");
			ImGui::EndTabItem();
		}
		ImGui::EndDisabled();

		ImGui::EndTabBar();
	
	}
}
