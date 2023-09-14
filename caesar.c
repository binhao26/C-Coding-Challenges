/**
 * A program that encrypts messages using Caesar's cipher
 * From CS50 lecture 2 array problem set
 * https://cs50.harvard.edu/x/2023/psets/2/caesar/
 * */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>

// ASCII numeric values represent low&up case alphabet letters
#define A 65
#define Z 90
#define a 97
#define z 122

#define MAXIMUM_TEXT_LENGTH 100
// arrays to hold upper and lower case letters for processing
char alphabet_up[26];
char alphabet_low[26];

void encrypt_text(char plain_text[], int plain_text_length, int key);
void decrypt_text(char plain_text[], int plain_text_length, int key);

int main() {

	char plain_text[MAXIMUM_TEXT_LENGTH];
	int plain_text_length = 0;

	printf("Enter plain text below\n");

	int input;
	while ((input = getchar()) != '\n') {

		plain_text[plain_text_length] = input;
		plain_text_length++;

	}

	int key = 0;
	// The numeric key for encrypting and decrpting
	// Must > 0
	do {
		printf("Enter key: ");
		scanf("%d", &key);

		if (key <= 0) printf("invalid key, try again\n");
	}while(key <= 0);
	

	// initialize alphabet_up with all A-Z letters
	for (int i = A, j = 0; i <= Z; i++, j++) {
		alphabet_up[j] = i;
	}
	// initialize lower case alphabet with all a-z letters
	for (int i = a, j = 0; i <= z; i++, j++) {
		alphabet_low[j] = i;
	}

	
	encrypt_text(plain_text, plain_text_length, key);
	for (int i = 0; i < plain_text_length; i++) {
		printf("%c", plain_text[i]);
	}

	printf("decrypt text below\n");

	decrypt_text(plain_text, plain_text_length, key);



	for (int i = 0; i < plain_text_length; i++) {
		printf("%c", plain_text[i]);
	}
	
    return 0;
}

/**
 * Encrypt plain_text by finding the letter's
 * fixed position in alphabet A-Z or a-z, then shifting that
 * position forward by key steps
 * */
void encrypt_text(char plain_text[], int plain_text_length, int key) {
	int forward_steps;
	for (int i = 0; i < plain_text_length; i++) {

		if ((plain_text[i] >= 'a' && plain_text[i] <= 'z') || (plain_text[i] >= 'A' && plain_text[i] <= 'Z')) {
			// change all letters in plain_text to upper case for ease of processing
			char plain_letter = toupper(plain_text[i]);
			

			
			

			for (int j = 0; j < 26; j++) {

				if (plain_letter == alphabet_up[j]) {
					// shift letter's index position in alphabet by key step
					// % 26 ensures, if j + key exceeded 26, it goes back 0 - 26-1 range
					forward_steps = (j + key) % 26; 
					

					

					// assign cipher char to coreesponding low or upper case char in plaintext
					if (islower(plain_text[i]) > 0 ) {
						plain_text[i] = alphabet_low[forward_steps];
					}
					else {
						plain_text[i] = alphabet_up[forward_steps];
					}
					
					break;


				}
				

			}

		}
		
		

	}

}


/**
 * Decrypt plain_text through
 * reverting each letter by key steps
 * */
void decrypt_text(char plain_text[], int plain_text_length, int key) {

	for (int i = 0; i < plain_text_length; i++) {

		char plain_letter = toupper(plain_text[i]);
			

			
			

			for (int j = 0; j < 26; j++) {

				if (plain_letter == alphabet_up[j]) {
					
					int forward_steps = (j - key) % 26; // each encrypted letter index is subtracted by key steps to revert back to original index in alphabet.

					// assign cipher char to coreesponding low or upper case char in plaintext
					if (islower(plain_text[i]) > 0 ) {
						plain_text[i] = alphabet_low[forward_steps];
					}
					else {
						plain_text[i] = alphabet_up[forward_steps];
					}
					
					break;


				}
				

			}
	}
}

