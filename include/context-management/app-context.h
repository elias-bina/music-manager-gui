#ifndef MMG_CONTEXT_MANAGEMENT_APP_CONTEXT
#define MMG_CONTEXT_MANAGEMENT_APP_CONTEXT

#include "ressources-loading/db-manager.h"

#include "ui/widgets/add-song.h"
#include "ui/widgets/song-list.h"
#include "ui/widgets/current-song.h"

class AppContext
{
private:
	/* data */
public:
	AppContext(/* args */);
	~AppContext();

	DbManager _dbManager;

	CurrentSongWidget _currentSong;
	SongWidgetList _songWidgets;
	AddSongWidget _addSongWidget;

	void saveDatabase();
};

void add_song_to_list(void* user_param, std::string name, std::string link);


#endif
