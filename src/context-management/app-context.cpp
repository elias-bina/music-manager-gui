
#include "context-management/app-context.h"

AppContext::AppContext(/* args */)
{
	_songWidgets._current_song = &_currentSong;
}

AppContext::~AppContext()
{
}