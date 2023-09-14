/**
 * This is a codewar problem - Who likes it?
 * It mimics the like system from social media platforms like facebook
 * https://www.codewars.com/kata/5266876b8f4bf2da9b000362
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
char *int_to_char(int n);
char *like(int name_length, char *const names[name_length]);

int main() {

	int name_length = 8;
	char *names[name_length];
	names[0] = "alex"; 
	names[1] = "jones"; 
	names[2] = "kan";
	names[3] = "ting";
	names[4] = "michael";
	names[5] = "kemordia";
	names[6] = "pandalf";
	names[7] = "gary";



    char *like_sentence = like(name_length, names);

    printf("ans: %s", like_sentence);



	return 0;
}


/**
 * Determine the number of names in names[]
 * then concatenate some of these names with preset text
 * 
 * */
char *like(int name_length, char *const names[name_length]) {


	int counter = 0;
	
	char *like;
	static char temp_like[100] = " "; // store a single name
	int temp_like_length = 0; // represents the total concatenated string length, depending on name_length range 1 - 4

	// if array is empty
	if (name_length == 0) {
		like = "No one likes this";
		return like;
	}

	int char_counter = 0; // represents number of single letter in a name

	putchar('\n');
	
	// preset text
	const char *one_person_like = " likes this";
	const char *two_person_like_1 = " and ";
	const char *two_person_like_2 = " like this";
	const char *three_person_like1 = ", ";
	const char *three_person_like2 = " and ";
	const char *three_person_like3 = " like this";
	const char *four_person_like1 = ", ";
	const char *four_person_like2 = " and ";
	const char *four_person_like3 = "others like this";#

	int greater_name_len = name_length;
	// if there are more 3 names, set greater_name_len to 2. Iterate names[] and concatenate two names only, display the rest with a number
	if (name_length > 3) {
		greater_name_len = 2;
	}

	/**
	 * Iterate a single name in names[] at a time, depending on name_length
	 * concatenate a name to respective preset text
	 * */
	for (int i = 0; i < greater_name_len; i++) {
		while (*(names[i]+counter) != '\0') {
			temp_like[char_counter] = *(names[i]+counter);
					//printf("char_counter: %d | temp_like: %c", char_counter, temp_like[char_counter]);
			counter = counter + 1;
			char_counter = char_counter + 1; // record number of single letters in a name
			temp_like_length = temp_like_length + 1; // record number of single letters in a name
		}

		counter = 0; // reset counter for next name

		switch(name_length) {

			case 1:
				strcat(temp_like, one_person_like);
				temp_like_length+=11; // set length to number of chars in one_person_like
			break;

			case 2:
				// concatenate first name with two_person_like_1 when names[i = 0]
				if (i == 0) {
					strcat(temp_like, two_person_like_1);
					char_counter = char_counter + 5;
					temp_like_length+=5; // set length to number of chars in two_person_like
				}
				
			   // concatenate second name with two_person_like_2 when names[i = 1]
				if (i == 1) {
					strcat(temp_like, two_person_like_2);
					temp_like_length+=10;
					
				}
			break;

			case 3:

				// concatenate a single name with all three_person_likes 1 - 3 depending on i

				if (i == 0) {
					strcat(temp_like, three_person_like1);
					char_counter = char_counter + 2;
					temp_like_length = temp_like_length + 2;
				}

				if (i == 1) {
					strcat(temp_like, three_person_like2);
					char_counter = char_counter + 5;
					temp_like_length = temp_like_length + 5;
				}

				if (i == 2) {
					strcat(temp_like, three_person_like3);
					char_counter = char_counter + 10;
					temp_like_length = temp_like_length + 10;
				}
			break;

			// if more than 4 names in names[i], concatenate two names and display the rest with a number
			default:
				if (i == 0) {
					strcat(temp_like, four_person_like1);
					char_counter = char_counter + 2;
					temp_like_length = temp_like_length + 2;
				}

				if (i == 1) {
					strcat(temp_like, four_person_like2);
					char_counter = char_counter + 5;
					temp_like_length = temp_like_length + 5;
				}


			break;

		}

	}
	char *others = int_to_char(name_length - 2); // minus 2 to exclude two names that will appears on the sentence, and the rest as a digit
		int others_length = 0;
		int temp_others_len = 0; // its the irresi array length
		while(*(others + others_length) != '\0') {
			temp_others_len = temp_others_len + 1;
			others_length = others_length + 1;
		}
			//-------------------------------------------------
		char others_num[temp_others_len];
		others_num[1] = ' '; // has to set others_num[1] = ' ' due to initially, it always has [] char.
		temp_others_len = 0;
		others_length = 0;
		printf("-----------------------others_num is %c\n", others_num[1]);
		while(*(others + others_length) != '\0') {

			others_num[temp_others_len] = *(others + others_length);
			temp_others_len = temp_others_len + 1;
			others_length = others_length + 1;

		}
		printf("-----------------------others_num is %s\n", others_num);
		temp_others_len = 0;
		while(others_num[temp_others_len] != '\0') {
				//printf("4: temp_like[%d] is %c", char_counter, temp_like[char_counter]);
			temp_like[char_counter] = others_num[temp_others_len];
				//printf("4below: temp_like[%d] is %c", char_counter, temp_like[char_counter]);
			char_counter = char_counter + 1;
			temp_others_len = temp_others_len + 1;
				
		}
		strcat(temp_like, four_person_like3);

		return temp_like;


}

// convert the number name.length - 2, to a char for concatenating.
char *int_to_char(int n) {

	char char_number[15];
	int i = 0;
	char temp;

	while (n != 0) {
		temp = (n % 10) + '0';
		//printf("temp: %c\n", temp);
		char_number[i] = temp;
		n = n / 10;
		i = i + 1;
	}

	//printf("%s", char_number);

	//reverse
	static char irreversed_char[15];

	for (int k = i - 1, j = 0; k >= 0; k--, j++) {
		irreversed_char[j] = char_number[k];

	}

	//printf("%s", irreversed_char);

	return irreversed_char;
}

