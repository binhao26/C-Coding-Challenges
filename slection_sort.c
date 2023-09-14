+#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// '\0' is treated the same as 0 in decinmal, '\0' is place at end of string

// bool digit_seen[10] = {false};  - assign all index values to false
// int a[] = {2, 3, [5] = 10, [3] = 2......[n] = n}
// if (digit_seen[digit]) - digit_seen[digit] = true

// Netch's Touch, Talfyg's Treachery, Treasure Hunter, True-Sworn Fury

#define WALKIE_LENGTH 10
#define N_OF_DIRECTIONS 4
#define win_score 4

#define UP 0
#define DOWNLOAD 1
#define RIGHT 2
#define LEFT 3

#define A 65
#define Z 90

#define NUMBER_LENGTH sizeof(random_numbers) / sizeof(random_numbers[0])



void check_paths(bool blocked_paths[], char random_walkie[][10], int up_down, int left_right);
int instruct_path(int direction, bool blocked_paths[]);
int get_smallest(int n, int m);

/**
 * Incomplete with draft code but worked
 * */
int main() {

	int size;
	int count = 0;
	int number;
	printf("Enter size: ");
	scanf("%d", &size);

	int random_numbers[size]; 
	printf("enter series of number:");
	while (count < size) {
		scanf("%d", &number);
		random_numbers[count] = number;
		count++;
	}

	 	// 4, 5, 7, 2, 8, 1, 3

	int i, j;
	int largest, smallest;


	int smallest_index;
	for (i = 0; i < NUMBER_LENGTH; i++) {

		smallest = random_numbers[i];
		smallest_index = i;

		for (j = i + 1; j < NUMBER_LENGTH; j++) {

			if (smallest > random_numbers[j]) {

				smallest = random_numbers[j];
				smallest_index = j;
			}

		}

		random_numbers[smallest_index] = random_numbers[i];
		random_numbers[i] = smallest;


	}
	
	printf("smallest elements: \n");

	for (i = 0; i < size; i++) {
		printf(" %d", random_numbers[i]);
	}
	return 0;



}


