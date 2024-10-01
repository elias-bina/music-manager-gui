#include "imgui/imgui.h"

#include "context-management/top-menu.h"

TopMenu::TopMenu(AppContext* context): _context{context}
{
}

TopMenu::~TopMenu()
{
}


void TopMenu::Save(){
  _context->saveDatabase();
  printf("Save database file\n");	
}


void TopMenu::Render(){
  if(ImGui::Shortcut(ImGuiMod_Ctrl | ImGuiKey_S, ImGuiInputFlags_None)){
    Save();
  }

  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::BeginMenu("Add Song")) {
      if (ImGui::MenuItem("Create Song From Link", "Ctrl+L")) { 
        printf("Will create Song From Link\n");
      }
      if (ImGui::MenuItem("Create Song From Youtube", "Ctrl+Y")) { 
        printf("Will create Song From Youtube\n");
      }
      if (ImGui::MenuItem("Open", "Ctrl+O")) { 
        printf("Will open database file\n");
      }
      if (ImGui::MenuItem("Save", "Ctrl+S")) {
        Save();
      }
      if (ImGui::MenuItem("Save as..")) { 
        printf("Will save new database file\n");
      }
      ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Settings")) {
      if (ImGui::MenuItem("Choose download folder")) { 
        printf("Will allow to change download folder\n");
      }
      ImGui::EndMenu();
    }

    ImGui::EndMainMenuBar();
  }
}
