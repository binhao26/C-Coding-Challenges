/**
 * A dice game from the book - C programming the modern approach
 * **Rules:
 * 1)Roll two dice(hint: use rand)
 * 2)Sum of the spots on two upward faces is calculated
 * 3)7 or 11 on first throw player wins
 * 4)2, 3 or 12 on first throw player loses
 * 5)First throw of 4,5,6,8,9,10 becomes players point.
 * 6)Player must roll his dices till he win or lose:
◦* If he rolled his point before rolling 7 he wins, if he rolled 7 he loses
 * 
 * */


#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


void check_paths(bool blocked_paths[], char random_walkie[][10], int up_down, int left_right);
int instruct_path(int direction, bool blocked_paths[]);
int get_smallest(int n, int m);
int power(int x, int n);
int roll_dice(void);
bool play_game(void);


int main() {

	srand(time(NULL));

	int wins, loses;
	char input;

	bool game_finished = false;

	while (!game_finished) {
		if (play_game() == true) {
			wins++;
			printf("You won, play again?: ");
			scanf("%c", &input);

			if (input == 'y') {
				game_finished = false;
			
			}
			
		}
		else {
			loses++;
			printf("You lost, play again?: ");
			scanf("%c", &input);

			if (input == 'y') {
				game_finished = false;
				
			}
			
		}
	}

	printf("Wins: %d  Loses: %d", wins, loses);


	return 0;



}

// Initialize two dice
int roll_dice(void) {

	int dice_1 = rand() % 6;
	printf("dice1 is %d\n", dice_1);
	int dice_2 = rand() % 6 + 2;
	printf("dice2 is %d\n", dice_2);

	return dice_1 + dice_2;

}
// play_game returns true to indicate a win
bool play_game(void) {
	int sum;
	// first round of the roll
	sum = roll_dice();
	printf("You rolled %d\n", sum);

	bool game_continue = true;

	if (sum == 7 || sum == 11){
		return true;
	}
	if (sum == 2 || sum == 3 || sum == 12) {
		return false;
	}

	int point = sum;
	printf("Your point is %d\n", point);
	
	// round continues to roll till a win or lose condition met.
	int rolled_dice;
	while (game_continue) {
		rolled_dice = roll_dice();
		printf("You rolled %d\n", rolled_dice);
		if (rolled_dice == point) {
			return true;
			game_continue = false;
		}
		if (rolled_dice == 7) {
			return false;
			game_continue = false;
		}
	}

}








