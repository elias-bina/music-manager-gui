#include <stdio.h>
#include "string.h"

#include "ressources-loading/db-manager.h"

sqlite3* DbManager::openDb(){
	sqlite3 *db;
	sqlite3_open(_path.c_str(), &db);
	return db;
}

static bool wrap_prepare(sqlite3* db, const char* sql, sqlite3_stmt** stmt){
	int rc = sqlite3_prepare_v2(db, sql, -1, stmt, 0);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		return false;
	}else{
		fprintf(stdout, "Prepared statement successfully\n");
	}
	return true;
}

static bool wrap_text_bind(sqlite3* db, sqlite3_stmt* stmt, int index, const char* text){
	char* txt = strdup(text);
	int rc = sqlite3_bind_text(stmt, index, txt, (int)strlen(txt), NULL);
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		return false;
	}else{
		fprintf(stdout, "Bind text successfully\n");
	}
	return true;
}


bool DbManager::exec_sql(sqlite3 *db, sqlite3_stmt* stmt){
	int rc = 0;

	rc = sqlite3_step(stmt);
	while (rc == SQLITE_ROW ) {

		if( rc != SQLITE_OK ){
			fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
			return false;
		}else{
			fprintf(stdout, "Table created successfully\n");
		}
		rc = sqlite3_step( stmt );
	}

	rc = sqlite3_finalize( stmt ); 
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
		return false;
	}else{
		fprintf(stdout, "Table created successfully\n");
	}

	sqlite3_close(db);
	return true;
}

void DbManager::removeDatabase(){
	remove(_path.c_str());
}

bool DbManager::createDatabase(){
	sqlite3 *db = openDb();
	sqlite3_stmt* stmt = 0;

	if(!wrap_prepare(db, "CREATE TABLE IF NOT EXISTS songs (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, link TEXT);", &stmt)){
		return false;
	}

	return exec_sql(db, stmt);
}

bool DbManager::insertSong(SongWidget* song){
	sqlite3 *db = openDb();
	sqlite3_stmt* stmt = 0;

	if(!wrap_prepare(db, "INSERT INTO songs (name, link) VALUES (?, ?);", &stmt))
		return false;

	if(!wrap_text_bind(db, stmt, 1, song->getName().c_str()))
		return false;
	
	if(!wrap_text_bind(db, stmt, 2, song->getLink().c_str()))
		return false;

	return exec_sql(db, stmt);
}



DbManager::DbManager(std::string path): _path{path}
{

}
	
DbManager::~DbManager(){
}