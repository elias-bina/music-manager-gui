#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include "GLFW/glfw3.h"

#include "sqlite3.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#include "context-management/app-context.h"
#include "context-management/top-menu.h"

#include "ui/tabs/render-tabs.h"

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
	TopMenu topMenu(&context);

	context._dbManager.createDatabase();

	context._songWidgets.AddSong("Nier Replicant 1.22 - Emil - Sacrifice", "https://www.youtube.com/watch?v=geghzmOuYR8");
	context._songWidgets.AddSong("Chime & DNAKM - Make 'em Proud", "https://www.youtube.com/watch?v=iVAamocy_OI");
	context._songWidgets.AddSong("Transistor - Cut Apart", "https://www.youtube.com/watch?v=JzaEWa0BHcA");
	context._songWidgets.AddSong("Mob Psycho 100 - Esprit Rampant", "https://www.youtube.com/watch?v=XQBSuUHOoRY");
	context._songWidgets.AddSong("Dead Cells - The Crypt", "https://www.youtube.com/watch?v=eJehlLCsBH4");
	context._songWidgets.AddSong("Mo:Astray - Escape", "https://www.youtube.com/watch?v=okFvYxHLY3I");
	context._songWidgets.AddSong("Mo:Astray - The Errors", "https://www.youtube.com/watch?v=qo9rJbltr6A");
	context._songWidgets.AddSong("Mo:Astray - Surface B", "https://www.youtube.com/watch?v=v2BSL7UDcHA");
	context._songWidgets.AddSong("Mo:Astray - Unknown Area", "https://www.youtube.com/watch?v=HWg4oS001tA");
	context._songWidgets.AddSong("Mo:Astray - Fallen", "https://www.youtube.com/watch?v=XGTRD8xrpkc");
	context._songWidgets.AddSong("Sonic Colors - Out of Breath", "https://www.youtube.com/watch?v=RmegSe3Inmc");
	context._songWidgets.AddSong("Pokemon Mystery Dungeon Explorers of Sky - Time Gear", "https://www.youtube.com/watch?v=afo8lPbvobc");
	context._songWidgets.AddSong("Pokemon Mystery Dungeon Explorers of Sky - I saw something again...", "https://www.youtube.com/watch?v=0WJtVAK0ldI");
	context._songWidgets.AddSong("Bravely default - Serpent Eating the Ground (4:40)", "https://www.youtube.com/watch?v=boxhke2611E");
	context._songWidgets.AddSong("Sonic and the Black Knight - Knight of the wind", "https://www.youtube.com/watch?v=pNB4Cy4mftI");
	context._songWidgets.AddSong("Sonic and the Black Knight - Shrouded Forest", "https://www.youtube.com/watch?v=RvxeR-uhsmY");
	context._songWidgets.AddSong("Sonic and the Black Knight - Battle Menu", "https://www.youtube.com/watch?v=Ti3PscmcETE");
	context._songWidgets.AddSong("Sonic and the Black Knight - With Me", "https://www.youtube.com/watch?v=L9I9qsKJL5s");
	context._songWidgets.AddSong("Getsix - Valhalla (0:54)", "https://www.youtube.com/watch?v=X78-3KjFGo4");
	context._songWidgets.AddSong("Feint - Let me go (1:06)", "https://www.youtube.com/watch?v=kJQIIc5T__8");
	context._songWidgets.AddSong("MDK - Lightspeed (0:51)", "https://www.youtube.com/watch?v=9ePz9RKRU1s");
	context._songWidgets.AddSong("Mob Psycho 100 - Explosion of Mobs Feelings (0:14)", "https://www.youtube.com/watch?v=ZiMWBCxUU9s");
	context._songWidgets.AddSong("Sonic Rush - Vela-Nova (Part 2)", "https://www.youtube.com/watch?v=pNhyEMKQ6XU");
	context._songWidgets.AddSong("Sonic Rush - A New Day", "https://www.youtube.com/watch?v=NMBL43I3r4g");
	context._songWidgets.AddSong("Sonic Rush - Bomber Barbara", "https://www.youtube.com/watch?v=L4KIxqTYGGI");
	context._songWidgets.AddSong("Sonic Rush - Bomber Barbara (Silent Dreams Remix)", "https://www.youtube.com/watch?v=P6L-jO28O9U");



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

				topMenu.Render();
				

				ImGui::BeginGroup();
				RenderTabsManagement(context);
				ImGui::EndGroup();

				ImGui::SameLine();
				
				ImGui::BeginGroup();


				ImGui::NewLine();
				// ImGui::Spacing();

				ImGui::SeparatorText("Selected Song");

				context._currentSong.Render();

				ImVec2 size = ImGui::GetWindowSize();


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

	printf("Nique ta mère\n");

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}