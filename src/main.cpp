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

	context.songWidgets.AddSong("Emil - Sacrifice");
	context.songWidgets.AddSong("Chime & DNAKM- Make 'em Proud");

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

				RenderTabsManagement(context);

				ImGui::SeparatorText("Global Display");

				ImVec2 size = ImGui::GetWindowSize();

				if (ImGui::Button("Press me"))
					printf("Button has been pressed\n");
				
				ImGui::Text("Size of Window: (%f,%f)", size.x, size.y);
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