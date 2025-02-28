#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "/mnt/c/coding/clang/project/snake_game/src/kbhit.h"

#define ROWS 10
#define COLS 10

int gameover = 0;

void draw_table(int table_curr[ROWS][COLS]);
void prev_equal_curr(int table_prev[ROWS][COLS], int table_curr[ROWS][COLS]);
int neighbour_count(int table_prev[ROWS][COLS], int r, int c);
void *check_exit();

int main(int argc, char *argv[]) {
	pthread_t tid;

	// create a thread to check user input
	pthread_create(&tid, NULL, check_exit, NULL);
	pthread_detach(tid); // don't need return value

	int table_prev[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},		
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

	int table_curr[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								  {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
								  {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},		
							 	  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

	int round = 0;
	while(!gameover) {
		if(round == 0) {
			printf("Initializing game table\n");
		} else {
			printf("Round %d\n", round);
		}
		
		sleep(1);

		draw_table(table_curr);
		
		prev_equal_curr(table_prev, table_curr);
		
		// game logic
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				int neighbour_lives = neighbour_count(table_prev, i, j);

				// live to next generation
				if (table_prev[i][j] == 1 && (neighbour_lives == 2 || neighbour_lives == 3)) {
					table_curr[i][j] = 1;
				} 
				// reproduction
				else if (table_prev[i][j] == 0 && neighbour_lives == 3) {
					table_curr[i][j] = 1;
				}
				// underpopulation
				else 
				{
					table_curr[i][j] = 0;
				}
			}
		}
		round++;
	}
	
	printf("Game over\n");

	return 0;
}

void draw_table(int table_curr[ROWS][COLS]) {
	system("clear");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf(" %d", table_curr[i][j]);
		}
		printf("\n");
	}
}

void prev_equal_curr(int table_prev[ROWS][COLS], int table_curr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			table_prev[i][j] = table_curr[i][j];	
		}
	}
}

int neighbour_count(int table_prev[ROWS][COLS], int r, int c) {
	int count = 0;

	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++) {
			if (i < 0 || j < 0 || i >= ROWS || j >= COLS || (i == r && j == c)) {
				continue;
			}

			if (table_prev[i][j] == 1){
				count++;
			}
		}
	}
	return count;
}

void *check_exit() {
	while(!gameover) {
		if (kbhit() && getchar() == 'x') {
			gameover = 1;
		}
	}
	return NULL;
}
