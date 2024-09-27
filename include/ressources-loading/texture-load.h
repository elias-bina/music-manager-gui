#ifndef MMG_UI_RESSOURCE_LOADING_TEXTURE_LOAD
#define MMG_UI_RESSOURCE_LOADING_TEXTURE_LOAD

#include "GLFW/glfw3.h"

class LoadedTexture
{
public:
	int width = 0;
	int height = 0;
	GLuint texture = 0;
};

bool LoadTextureFromMemory(const void* data, size_t data_size, LoadedTexture* texture);
bool LoadTextureFromFile(const char* file_name, LoadedTexture* texture);


#endif