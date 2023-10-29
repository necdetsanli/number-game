#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "scoreboard.h"

sqlite3* open_db(void)
{
    sqlite3 *db; 

    if (sqlite3_open(DB_NAME, &db)) {
        fprintf(stderr, "Can not open database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    return db;
}

void close_db(sqlite3* db)
{
    sqlite3_close(db);
}

void create_table(sqlite3* db)
{
    char* zerrmsg;
    const char *sql = "CREATE TABLE IF NOT EXISTS Scoreboard(PlayerName TEXT NOT NULL, Score INT);";

    if (sqlite3_exec(db, sql, NULL, 0, &zerrmsg) != SQLITE_OK) {
        printf("Cannot create table: %s\n", sqlite3_errmsg(db));
        sqlite3_free(zerrmsg);
    }
}

void insert_table(sqlite3* db, const char* name, int score)
{
    char* zerrmsg;
    char* sql;
    
    if ((sql = sqlite3_mprintf("INSERT INTO SCOREBOARD VALUES(%Q, %d)", name, score)) == NULL) {
        fprintf(stderr, "Cannot allocate memory for sqlite3_mprintf!\n");
        exit(EXIT_FAILURE);
    }

    if (sqlite3_exec(db, sql, NULL, NULL, &zerrmsg)) {
        fprintf(stderr, "sqlite3_exec: %s", zerrmsg);
    }

    sqlite3_free(sql);
}