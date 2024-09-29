
#include "context-management/app-context.h"

AppContext::AppContext(/* args */): _dbManager{DbManager("songs.db")}
{
	_songWidgets._current_song = &_currentSong;
}

AppContext::~AppContext()
{
}

void AppContext::saveDatabase() {
	_dbManager.removeDatabase();
	_dbManager.createDatabase();
	for (std::shared_ptr<SongWidget> song : _songWidgets._song_list)
	{
		_dbManager.insertSong(song.get());
	}
	
}