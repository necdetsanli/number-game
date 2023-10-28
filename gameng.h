#include <time.h>

#define POINT  1
#define STREAK POINT * 2
#define ESC    27

void randomize(void);
void clear_input_buffer(void);
void print_welcome(void);
void print_score(int score, int round);
int generate_num(void);
void game_eng(void);
