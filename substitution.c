/**
 * Problem set from CS50 lecture 2 - Array
 * 
 * "In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) 
 * a message by replacing every letter with another letter. 
 * To do so, we use a key: in this case, 
 * a mapping of each of the letters of the alphabet to the letter it should 
 * correspond to when we encrypt it. To “decrypt” the message, the receiver of the message 
 * would need to know the key, so that they can reverse the process: translating the encrypt text 
 * (generally called ciphertext) back into the original message (generally called plaintext)."
 * 
 * https://cs50.harvard.edu/x/2023/psets/2/substitution/
 * */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>

#define MAXIMUM_TEXT_SIZE 200
#define TRUE 1
#define FALSE 0

#define A 65
#define Z 90
#define a 97
#define z 122

char alphabet_up[26];char alphabet_low[26];
void encrypt_text(char plain_text[], int plain_text_length, char key[], int key_length);
void decrypt_text(char plain_text[], int plain_text_length, char original_plain_text[], char key[], int key_length);

int main() {

	char key[26];
	int key_length = 0 ;
	char plain_text[MAXIMUM_TEXT_SIZE];
	int plain_text_length = 0;

	for (int i = A, j = 0; i <= Z; i++, j++) {
		alphabet_up[j] = i;
	}

	// 26 alphabet chars onl;y
	// length 26
	// each letter appear once

	printf("Enter key: ");

	int input;
	while ((input = getchar()) != '\n') {

		if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
			key[key_length] = input;
			key_length++;
		}
		else {
			printf("Invalid characters");
			return 1;
		}

		
	}

	if (key_length > 26) {
		printf("Must not exceed 26 chars");
		return 1;
	}

	//convert both key[i] and key[j] to upper case for comparison. Repeated chars include both upper and lower case of same letter
	for (int i = 0; i <= key_length - 1; i++) { // i stops at second last for j to compare.

		char temp_upper_case_i = toupper(key[i]); 

		for (int j = i + 1; j < key_length; j++) { // compare the rest of the array with i

			char temp_upper_case_j = toupper(key[j]);

			if (temp_upper_case_i == temp_upper_case_j) {
				printf("Repeated characters! %c AND %c are repeated BYe", key[i], key[j]);
				return 1;
			}
		}
	}

	

	//********************Plain text input*************************//

	printf("Enter your text: ");

	while((input = getchar()) != '\n') {

		plain_text[plain_text_length] = input;
		plain_text_length++;

	}

	// define a original copy of plain text, use in decrypt to revert back encrypted text to original plain text with correct case
	char original_plain_text[plain_text_length];
	strcpy(original_plain_text, plain_text);

	for(int i = 0; i < plain_text_length; i++) {
		printf("%c", plain_text[i]);
	}

	putchar('\n');


	encrypt_text(plain_text, plain_text_length, key, key_length);

	for(int i = 0; i < plain_text_length; i++) {
		printf("%c", plain_text[i]);
	}

	putchar('\n');

	printf("Decrypt text\n");

	decrypt_text(plain_text, plain_text_length, original_plain_text, key, key_length);

	for(int i = 0; i < plain_text_length; i++) {
		printf("%c", plain_text[i]);
	}






	return 0;
}

/**
 * works by mapping each letter in plain_text to alphabet[], then
 * use that matched index in alphabet[], to match the index of the letter
 * in key[]
 * Note: since alphabet[] are upper case, has to convert temp var plain_letter for
 * looking up index, then convert the letter to appropriate upper or lower case in key[]
 **/
void encrypt_text(char plain_text[], int plain_text_length, char key[], int key_length) {

	for (int i = 0; i < plain_text_length; i++) {

		char plain_letter = toupper(plain_text[i]);

		for (int j = 0; j < key_length; j++) {

			if (plain_letter == alphabet_up[j]) {

				plain_text[i] = key[j];
			}
		}
	}
}


/**
 * Similar to encrypt_text but works in reverse, with one extra param, 
 * original_plain_text[], it used to make sure each converting letter stay correct to their original
 * upper or lower case as in original_plain_text
 * first, for each encrypted letter, look up its index in key[]
 * then find out whether or not its upper or lower case in original_plain_text, 
 * then match that letter back to its original alphabet form in alphabet.
 * */
void decrypt_text(char plain_text[], int plain_text_length, char original_plain_text[], char key[], int key_length) {

	for (int i = 0; i < plain_text_length; i++) {

		char cipher_letter = plain_text[i];

		for (int j = 0; j < key_length; j++) {

			if (cipher_letter == key[j]) {

				if (original_plain_text[i] >= 'a' && original_plain_text[i] <= 'z') {

					plain_text[i] = tolower(alphabet_up[j]);
				}
				else {
					plain_text[i] = alphabet_up[j];
				}
			}
		}
	}
}