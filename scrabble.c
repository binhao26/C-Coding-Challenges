/**
 * Lab from CS50 lecture 2 - Array
 * 
 * "In the game of Scrabble, players create words to score points, 
 * and the number of points is the sum of the point values of each letter in the word."
 * 
 * https://cs50.harvard.edu/x/2023/labs/2/
 * */



#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>

#define A 65
#define Z 90
#define ALPHABET_LENGTH 26

#define MAXIMUM_TEXT_LENGTH 100

void filter_text(char text[], int len);
int compute_score(char text[], int len);



int main() {
	
	char user1_text[MAXIMUM_TEXT_LENGTH];
	char user2_text[MAXIMUM_TEXT_LENGTH];
	int user1_text_length = 0;
	int user2_text_length = 0;

	int input1;
	int input2;

	printf("User1: enter your text: ");
	
	while((input1 = getchar()) != '\n') {


		user1_text[user1_text_length] = input1;
		user1_text_length++;

	}

	printf("User2: enter your text: ");
	
	while((input2 = getchar()) != '\n') {


		user2_text[user2_text_length] = input2;
		user2_text_length++;

	}

	/

	// call filter func to clear non letter chars, also convert all letters to upper case/////////

	filter_text(user1_text, user1_text_length);
	int filtered_usr1_len = strlen(user1_text); // retrieve new text length of filtered text

	filter_text(user2_text, user2_text_length);
	int filtered_usr2_len = strlen(user2_text);

	
	//compute users scores

	int usr1_score = compute_score(user1_text, filtered_usr1_len);
	int usr2_score = compute_score(user2_text, filtered_usr2_len);

	printf("User 1 score is: %d\n", usr1_score);
	printf("User 2 score is: %d\n", usr2_score);

	if (usr1_score > usr2_score) {
		printf("The winner is user1");
	}
	else if (usr2_score > usr1_score) {
		printf("The winner is user2");
	}
	else {
		printf("Its a draw!");
	}


    return 0;
}

/**
 * clear non letter chars in text then convert all 
 * letters to upper case 
*/

void filter_text(char text[], int length) {
	//use strcpy to replace orginal text[] withj filtered_text after filtering
	char filtered_sentence[length];
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			filtered_sentence[counter] = text[i];
			counter++;
		}

		if (text[i] >= 'A' && text[i] <= 'Z') {
			filtered_sentence[counter] = text[i];
			counter++;
		}

	}

	strcpy(text, filtered_sentence);

	//convert filtered text to upper case
	for (int i = 0; i < counter; i++) {
		text[i] = toupper(text[i]);
	}

	
	
}

/**
 * compute scores with dummy scores in scores array, each index of 
 * scores[] are corrspond to indexes of alphabet[]
 * locate the letter of text which corresponds in alphabet, 
 * then use that index to locate the score corresponding to the position of that letter
 * in alphabet[]
 */

int compute_score(char text[], int length) {

	char alphabet[26];
	// initialize alphabet array with 26 letters in upper case
	for (int i = A, j = 0; i <= Z; i++, j++) {

		alphabet[j] = i;

	}

	// dummy scores for each corrsponding letters in alphabet array
	int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

	int score = 0;

	// find each letter of text's index in alphabet[], then use that index position in scores[] to find the appropriate score 
	// then add to sum.
	for (int i = 0; i < length; i++) {

		for (int j = 0; j < ALPHABET_LENGTH; j ++) {
			if (text[i] == alphabet[j]) {
				score+=scores[j];
			}
		}
	}

	return score;



	
}