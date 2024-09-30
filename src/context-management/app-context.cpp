
#include "context-management/app-context.h"


void add_song_to_list(void* user_param, std::string name, std::string link) {
	AppContext* appContext = static_cast<AppContext*>(user_param);
	appContext->_songWidgets.AddSong(name, link);
}

AppContext::AppContext(/* args */): _dbManager{DbManager("songs.db")}, _addSongWidget{AddSongWidget(add_song_to_list, this)}
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