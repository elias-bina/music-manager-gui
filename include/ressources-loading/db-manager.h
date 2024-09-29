#ifndef MMG_UI_RESSOURCE_LOADING_DB_MANAGER
#define MMG_UI_RESSOURCE_LOADING_DB_MANAGER

#include <string>

#include "sqlite3.h"

#include "ui/widgets/song.h"

class DbManager {
private:
	std::string _path;

	bool exec_sql(sqlite3 *db, sqlite3_stmt* stmt);
	sqlite3* openDb();

public:

	void removeDatabase();
	bool createDatabase();

	bool insertSong(SongWidget* song);

	DbManager(std::string path);
	~DbManager();
};


#endif