#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <sqlite3.h>
#include <string.h>
#include "gameng.h"
#include "scoreboard.h"

void randomize(void)
{
	srand((unsigned)time(NULL));
}

void sgets(char* p)
{
	int c;

    clear_input_buffer();

	while ((c = getchar()) != '\n') {
		*p++ = (char)c;
	}

	*p = '\0';
}

void clear_input_buffer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		;
}


void print_welcome(void)
{
    printf("\n\n");
    printf("*************************************************\n");
    printf("Welcome to the world's most simple and fun game.\n");
    printf("For every round, there will be a number you need to find out...\n");
    printf("If you find it out you will earn %d points\n", POINT);
    printf("You can save your score and see your position at the leaderboard later.\n");
    printf("To quit the game please press enter -1 as guessed number\n");
    printf("It seems easy right? Don't be too sure!..\n");
    printf("*************************************************\n");

    printf("\n\n\n");
}

void print_score(int score, int round)
{
    printf("You correctly guessed %d numbers out of %d numbers!\n", score, round);
    printf("Your success rate is nearly = %%%0.2f\n", (double)score / round * 100);
    printf("Keep up the good work!\n");

    printf("\n\n");
}

int generate_num(void)
{
    return rand() % 10; 
}

int game_eng(void)
{
    int guess, num, score, round, streak;
    int total_points, ds_count, ts_count;

    total_points = ds_count = ts_count = score = round = streak = 0; 

    while (1) {
        printf("\n\nROUND %00d\n", round);
        num = generate_num();
        
        printf("Your guess: ");
        scanf("%d", &guess);

        if (guess == -1)
            break; 

        if (num == guess) {
            printf("Correct!\n");
            score += POINT;
            ++streak; 
        }
        else {
            printf("Try again!\n");
            if (streak != 0)
                --streak;
        }

        if (streak == DOUBLE_STREAK) {
            printf("Double Streak!!!!\n");
            ds_count++;
        }

         if (streak == TRIPLE_STREAK) {
            printf("Triple Streak!!!!\n");
            ts_count++;
            streak = 0;
        }

        ++round;
    }

    total_points = 2 * ds_count + 3 * ts_count + score;

    print_score(score, round);

    return total_points;   
}

char* get_username(void)
{
    char* username = (char*)malloc(sizeof(char) * 64);
    
    printf("Username: ");
    sgets(username);
    putchar('\n');

    return username;
}

void save_to_db(sqlite3* db, int score)
{
    int c;
    char* username;

    clear_input_buffer();

    printf("Would you like to save your score to scoreboard(y/N)?: ");
    c = getchar();
    putchar('\n');

    if (tolower(c) == 'y') {
        username = get_username();
        insert_table(db, username, score);
    }
    
    free(username);
}   