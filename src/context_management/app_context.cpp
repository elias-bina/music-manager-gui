
#include "context_management/app_context.h"

AppContext::AppContext(/* args */)
{
	_songWidgets._current_song = &_currentSong;
}

AppContext::~AppContext()
{
}