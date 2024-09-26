#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include "GLFW/glfw3.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#include "ui/tabs/render_tabs.h"

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**) {
	// Setup window
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Music Manager", NULL, NULL);
	if (window == NULL)
		return 1;
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // This enables vsync so we dont render frames we dont need

	// Setup ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark(); // you can also use ImGui::StyleColorsClassic();


	// Choose backend
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();

	// Definitions
	bool show_main_window = true;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f); // backbuffer color
	AppContext context;

	context._songWidgets.AddSong("Emil - Sacrifice");
	context._songWidgets.AddSong("Chime & DNAKM - Make 'em Proud");
	context._songWidgets.AddSong("Transistor - Cut Apart");
	context._songWidgets.AddSong("Mob Psycho 100 - Esprit Rampant");
	context._songWidgets.AddSong("Dead Cells - The Crypt");
	context._songWidgets.AddSong("Mo:Astray - Escape");
	context._songWidgets.AddSong("Mo:Astray - The Errors");
	context._songWidgets.AddSong("Mo:Astray - Surface B");
	context._songWidgets.AddSong("Mo:Astray - Unknown Area");
	context._songWidgets.AddSong("Mo:Astray - Fallen");
	context._songWidgets.AddSong("Sonic Colors - Out of Breath");
	context._songWidgets.AddSong("Pokemon Mystery Dungeon Explorers of Sky - Time Gear");
	context._songWidgets.AddSong("Pokemon Mystery Dungeon Explorers of Sky - I saw something again...");
	context._songWidgets.AddSong("Bravely default - Serpent Eating the Ground (4:40)");
	context._songWidgets.AddSong("Sonic and the Black Knight - Knight of the wind");
	context._songWidgets.AddSong("Sonic and the Black Knight - Shrouded Forest");
	context._songWidgets.AddSong("Sonic and the Black Knight - Battle Menu");
	context._songWidgets.AddSong("Sonic and the Black Knight - With Me");
	context._songWidgets.AddSong("Getsix - Valhalla (0:54)");
	context._songWidgets.AddSong("Feint - Let me go (1:06)");
	context._songWidgets.AddSong("MDK - Lightspeed (0:51)");
	context._songWidgets.AddSong("Mob Psycho 100 - Explosion of Mobs Feelings (0:14)");
	context._songWidgets.AddSong("Sonic Rush - Vela-Nova (Part 2)");
	context._songWidgets.AddSong("Sonic Rush - A New Day");
	context._songWidgets.AddSong("Sonic Rush - Bomber Barbara");
	context._songWidgets.AddSong("Sonic Rush - Bomber Barbara (Silent Dreams Remix)");
	context._songWidgets.AddSong("Pokemon Scarlet & Violet - Final Fight");
	context._songWidgets.AddSong("One Punch Man - Seigi Shikkou");
	context._songWidgets.AddSong("Dead Cells - Fractured Shrines (0:06)");
	context._songWidgets.AddSong("Sonic Colors - Reach for the Stars");
	context._songWidgets.AddSong("Sonic Colors - Terminal Velocity");
	context._songWidgets.AddSong("Pokemon Mystery Dungeon Explorers of Sky - Oh no !");
	context._songWidgets.AddSong("Pokemon Mystery Dungeon The Bright Future - I Wont Say Goodbye (0:20)");
	context._songWidgets.AddSong("Pokemon Mystery Dungeon Explorers of Sky - Ending Theme");
	context._songWidgets.AddSong("Hollow Knight - Hornet");
	context._songWidgets.AddSong("Hollow Knight - Mantis Lords");
	context._songWidgets.AddSong("Hollow Knight - Truth, Beauty and Hatred");
	context._songWidgets.AddSong("Kirby and the Forgotten Land - Masked and Wild:DDD");
	context._songWidgets.AddSong("Kirby and the Forgotten Land - King Dedede, Roar of Dedede");
	context._songWidgets.AddSong("Kirby and the Forgotten Land - The King's Turn to Shine");
	context._songWidgets.AddSong("Super Pokemon Rumble - Charge Battle");
	context._songWidgets.AddSong("Sonic Frontiers - Cyber Space 1-5: Dropaholic (0:23)");
	context._songWidgets.AddSong("Sonic Frontiers - Cyber Space 1-7: Time Flyer");
	context._songWidgets.AddSong("Sonic Frontiers - Cyber Space 4-1: Exceed Match (0:49)");
	context._songWidgets.AddSong("Sonic Frontiers - Guardian: STRIDER");
	context._songWidgets.AddSong("Sonic Frontiers - Guardian: TANK");
	context._songWidgets.AddSong("Sonic Frontiers - Guardian: GHOST");
	context._songWidgets.AddSong("Sonic Frontiers - I'm here (0:30)");
	context._songWidgets.AddSong("Sonic Frontiers - Undefeatable (0:10)");
	context._songWidgets.AddSong("Sonic Frontiers - Break Through it all");
	context._songWidgets.AddSong("Sonic Frontiers - Find Your Flame (0:50)");
	context._songWidgets.AddSong("Sonic Frontiers - I'm Here (Orchestral Ver.)");
	context._songWidgets.AddSong("Sonic Frontiers - I'm Here (Revisited)");
	context._songWidgets.AddSong("Kid Icarus Uprising - Boss Fight 1");
	context._songWidgets.AddSong("Kid Icarus Uprising - Magnus's Theme");
	context._songWidgets.AddSong("Kid Icarus Uprising - Dark Pit");
	context._songWidgets.AddSong("Kid Icarus Uprising - Dark Pit's Theme");
	context._songWidgets.AddSong("Kid Icarus Uprising - Boss Theme 2");
	context._songWidgets.AddSong("Kid Icarus Uprising - Thunder Cloud Temple");
	context._songWidgets.AddSong("Kid Icarus Uprising - Chaos Island");
	context._songWidgets.AddSong("Kid Icarus Uprising - Lord Of The Underworld");
	context._songWidgets.AddSong("Kid Icarus Uprising - Together Menu");



	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); // Poll and handle events (inputs, window resize, etc.)

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration				|
									ImGuiWindowFlags_NoNav					|
									ImGuiWindowFlags_NoMove					|
									// ImGuiWindowFlags_NoSavedSettings		|
									ImGuiWindowFlags_MenuBar				|
									ImGuiWindowFlags_NoBringToFrontOnFocus;

		// Gui stuff
		if(show_main_window){
			const ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			if (ImGui::Begin("##Fullscreen window", &show_main_window, flags)){

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
							printf("Will save database file\n");	
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

				ImGui::BeginGroup();
				RenderTabsManagement(context);
				ImGui::EndGroup();

				ImGui::SameLine();
				
				ImGui::BeginGroup();

				ImGui::Text(" ");
				ImGui::SeparatorText("Selected Song");

				context._currentSong.Render();

				ImVec2 size = ImGui::GetWindowSize();

				if (ImGui::Button("Press me"))
					printf("Button has been pressed\n");
				
				ImGui::Text("Size of Window: (%f,%f); Framerate = %f", size.x, size.y, io.Framerate);
				ImGui::EndGroup();


				ImGui::End();
			}



		}



		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwMakeContextCurrent(window);
		glfwSwapBuffers(window);

	}
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}