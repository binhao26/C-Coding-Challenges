/**
 * A program that reverses a sentence
 * 
 * */


#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


#define WALKIE_LENGTH 10
#define N_OF_DIRECTIONS 4
#define win_score 4

#define UP 0
#define DOWNLOAD 1
#define RIGHT 2
#define LEFT 3

#define A 65
#define Z 90



void check_paths(bool blocked_paths[], char random_walkie[][10], int up_down, int left_right);
int instruct_path(int direction, bool blocked_paths[]);


int main() {

	int c;
	char sentence[100];
	int sentence_length = 0;

	char teminating_char;

	printf("Enter a sentence: ");
	while ((c = getchar()) != '\n') {
		if (c == '!' || c == '?' || c == '.') {
			teminating_char = c;
			break;
		}
		sentence[sentence_length] = c;
		sentence_length++;
	}

	int i, j, k;
	for (i = 0; i < sentence_length; i++) {
		printf("%c", sentence[i]);
	}
	putchar('\n');

	int word_len = 0;
	int word[10];
	bool is_space = false;
	printf("Reversal of sentence: ");
	for (j = sentence_length -  1; j >= 0; j--) {
		if (sentence[j] != ' ') { //  skip white space and store reversed letters in word[]
			word[word_len] = sentence[j];
			word_len++;
			
			
		}
		if (sentence[j] == ' ') is_space = true;

		// prints reversed letters in word[] along with white space in 
		while (is_space) {
			for (k = word_len - 1; k >= 0; k--) {
				printf("%c", word[k]);
			}
			putchar(' ');
			is_space = false;
			word_len = 0;
		}
		

	}

	for (k = word_len - 1; k >= 0; k--) {
		printf("%c", word[k]);
	}

	putchar(teminating_char); // original sentence





	return 0;
}

