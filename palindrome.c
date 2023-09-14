/**
 * Problem from book - The C programming the modern approach
 * Checks if a sentence(number included) is palindrome
 * */



#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define SENTENCE_MAX_LENGTH 100
void reverse_sentence(char *sentence, int counter);
bool isPalindrome(char sentence[], int length);
int main() {

	int counter = 0;
	char sentence[SENTENCE_MAX_LENGTH];
	int c;

	printf("Enter sentence: ");
	while((c = getchar()) != EOF) {
		if (c == '\n') break;
		sentence[counter] = c;
		counter++;
	}
	char letter1 = 'a';
	char letter2 = 'A';
	
	
	if (isPalindrome(sentence, counter) == true) {
		printf("it is palin");
	}
	else {
		printf("it is not!");
	}
	
	



	return 0;
}

void reverse_sentence(char *sentence, int counter) {
	for (int i = counter - 1; i >= 0; i--) {
		printf("%c", *(sentence + i));
	}
}

bool isPalindrome(char sentence[], int length) {
	int head = 0;
	int tail = length - 1;

	char head_letter, tail_letter;
	// if either character of head or tail is not a letter, head or tail increment to the next index in sentence for checking again.
	// if its a letter, loop stops. head and tail will contain letters.
	while (head < tail) {

		while (!((sentence[head] >= 'a' && sentence[head] <= 'z') || (sentence[head] >= 'A' && sentence[head] <= 'Z'))) {
			head = head + 1;
		}
		while (!((sentence[tail] >= 'a' && sentence[tail] <= 'z') || (sentence[tail] >= 'A' && sentence[tail] <= 'Z'))) {
			tail = tail - 1;
		}

		head_letter = tolower(sentence[head]);
		tail_letter = tolower(sentence[tail]);
		
		printf("head is %c\n", head_letter);
		printf("tail is %c\n", tail_letter);

		if (head_letter != tail_letter) {

			printf("if: head is %d, head_letter is %c\n", head, head_letter);
			printf("f: tail is %d, tail_letter is %c\n", tail, tail_letter);
			return false;
		}
		head = head + 1;
		tail = tail - 1;
	}
	return true;
}

