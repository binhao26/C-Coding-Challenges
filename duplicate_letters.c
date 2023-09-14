/**
 * A coding problem from codewar - count the number of duplicates
 * 
 * "Write a function that will return 
 * the count of distinct case-insensitive alphabetic 
 * characters and numeric digits that occur more than 
 * once in the input string. The input string can be assumed to 
 * contain only alphabets (both uppercase and lowercase) and numeric digits."
 * 
 * https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1
 * 
 * */



#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100
int duplicate_count(const char* text, int text_length);

int main() {

	/**
	 * hold at one element, iterate through the rest
	 * to find duplicate and increment counts if any 
	 * til end of array
	 * after sub loop ends, if (first)current element has duplicates
	 * store it to a varS
	 * 
	 * continue for then ext element, if 
	 * the next element is same as the var
	 * skip and check if its same as var
	 * if not, find duplicates
	 * https://uk.indeed.com/q-trainee-web-developer-jobs.html?vjk=51fe39e890ac7e83
	 * 
	 * 
	 * */

	char text[MAX_STRING_LENGTH];
	int word_length;
	int c;

	printf("Enter a single word: ");
	while((c = getchar()) != EOF && c != '\n') {
		text[word_length] = c;
		word_length++;
	}

	int repeats = duplicate_count(text, word_length);
	printf("Number of unique repeats: %d", repeats);


	return 0;
}

/**
 * Find unique repeated occurence of characters
 * (numeric included) appear in a single text
 * 
 * */

int duplicate_count(const char* text, int text_length) {
	int repeated = 0; // num of times a char is found repeated
	int unique_repeated = 0; 
	
	
	char current_char;

	char found_dup_chars[text_length]; // array to store found unique repeated chars
	found_dup_chars[0] = ' '; // set white space(trivial) at index 0 to kick start loop
	int duplicate_counts = 0; // use to traverse found_dup_chars
	

	for (int i = 0; i < text_length - 1; i++) {
		for (int k = 0; k < duplicate_counts; k++) { // Loop k won't execute for i = 0
			// if the current char is already a found member of found_dup_char, move to the next char in text
			// and set k = 0 to restart and compare from the beginning of found_dup_chars for the next text i + 1 char.
			if (text[i] == found_dup_chars[k]) { // ' ' i d
				i = i + 1; 
				k = 0;
			}
		}
		//after above loop k, current_char is made sure to be a non-repeated
		// char in found_dup_chars
		// loop j to find if rest of chars in text is same as current_char
		current_char = text[i];
		for (int j = i + 1; j < text_length; j++) {
			if (text[j] == current_char) {
				repeated = repeated + 1;
				
			}
		}
		// if repeated > 0, add current_char to found_dup_chars
		// and increment unique_repeated by 1
		if (repeated > 0) {
			duplicate_counts = duplicate_counts + 1;
			found_dup_chars[duplicate_counts] = current_char;
			printf("found unique repeated %c\n", found_dup_chars[duplicate_counts]);
			unique_repeated = unique_repeated + 1;
		}
		repeated = 0;
	}

	return unique_repeated;
}

