#include "gameng.h"
#include "scoreboard.h"

int main(void)
{
    int total_points;

    sqlite3* db = open_db();
    create_table(db);
    
    randomize();
    
    print_welcome();
    total_points = game_eng();

    save_to_db(db, total_points);
}