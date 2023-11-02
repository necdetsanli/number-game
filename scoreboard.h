#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <sqlite3.h>

#define DB_NAME "scoreboard.db"

sqlite3* open_db(void);
void close_db(sqlite3* db);
void create_table(sqlite3* db);
void insert_table(sqlite3* db, const char* name, int score);

#endif