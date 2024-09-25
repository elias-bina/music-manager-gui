#include "imgui/imgui.h"

#include "ui/tabs/render_tabs.h"

void RenderTabsManagement(AppContext &context)
{
	ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_Reorderable;
	if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
	{
		if (ImGui::BeginTabItem("List all Songs"))
		{
			context.songWidgets.Render();
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
