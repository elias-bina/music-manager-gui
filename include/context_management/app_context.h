#ifndef MMG_CONTEXT_MANAGEMENT_APP_CONTEXT
#define MMG_CONTEXT_MANAGEMENT_APP_CONTEXT

#include "ui/widgets/song-list.h"
#include "ui/widgets/current-song.h"

class AppContext
{
private:
	/* data */
public:
	AppContext(/* args */);
	~AppContext();

	CurrentSongWidget _currentSong;
	SongWidgetList _songWidgets;
};

#endif
