#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameng.h"

void randomize(void)
{
	srand((unsigned)time(NULL));
}

void clear_input_buffer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		; //null statement
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

void game_eng(void)
{
    int guess, num, score, round, streak;
    int c; 

    score = round = streak = 0; 
    
    randomize();
    print_welcome();

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

        if (streak == STREAK) {
            printf("Streak!!!!\n");
            streak = 0;
        }

        ++round;
    }

    print_score(score, round);    
}

