/**
 * Problem from book - The C Programming the modern approach
 * 
 *  "Write a program that prints an n x n magic square (a square arrangement of
 * the numbers 1, 2, ..., n^2 in which the sums of the rows, columns, and
 * diagonals are all the same). The user will specify the value of n:
 * This program creates a magic square of a specified size.
 * The size must be an odd number between 1 and 99."
 * */



#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int main() {

	// print initial square
	int magic_square[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			magic_square[i][j] = 0;
		}
		
	}
	magic_square[0][2] = 1;
	int counter = 1;

	int temp_i;
	int temp_j;

	int i = 0;
	int j = 2;
	int n = 5;
	int end = n * n;
	while (counter <= end) {
		temp_i = i;
		temp_j = j;
		--i;
		++j;
		++counter;
		if (i < 0) {
			i = n - 1;
		}
		if (j >= n) {
			j = 0;
		}
		
		if (magic_square[i][j] > 0) {
			i = temp_i + 1;
			j = temp_j;
		}
		magic_square[i][j] = counter;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf(" %d", magic_square[i][j]);
		}
		putchar('\n');
	}

	
	return 0;
}

