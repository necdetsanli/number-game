#ifndef GAMENG_H
#define GAMENG_H

#include <time.h>
#include <sqlite3.h>

#define POINT                 1
#define DOUBLE_STREAK POINT * 2
#define TRIPLE_STREAK POINT * 3

void randomize(void);
void clear_input_buffer(void);
void sgets(char* p);
void print_welcome(void);
void print_score(int score, int round);
int generate_num(void);
int game_eng(void);
void save_to_db(sqlite3* db, int score);

#endif