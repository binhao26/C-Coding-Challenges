/**
 * A program that shows the earilest train departure time
 * based on given time by user
 * 
 * */



#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define NUMBERS_OF_DEPARTURE 8
#define DEPARTURE_PM_LEN 5
#define DEPARTURE_AM_LEN 3
#define MAX_TIME_LENGTH 5

/**
	Problem can be found from Selection Statement,
	programming project 8

*/
int hour = 0;
int minutes = 0;

char get_time_prefix(char time[], int length);
void extract_time(char time[], int  length);
int main(void) {

	printf("Enter time:  ");
	
	int ch;
	char time[10];
	int length = 0;
	
	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			break;
		}
		time[length] = ch;
		length++;
	}

	extract_time(time, length);

	char time_prefix = get_time_prefix(time, length);

	// convert input time to minutes
	int input_minutes = (hour * 60) + minutes;
	printf("input minutes is %d\n", input_minutes);


	//all pre-set departure times in minutes, indexex correspond to their row positions,
	//top to bottom
	int departure_times_PM[DEPARTURE_PM_LEN];
	departure_times_PM[0] = 767;
	departure_times_PM[1] = 120;
	departure_times_PM[2] = 225;
	departure_times_PM[3] = 420;
	departure_times_PM[4] = 585;

	// seperate the times in two loops
	int departure_times_AM[DEPARTURE_AM_LEN];
	departure_times_AM[0] = 480;
	departure_times_AM[1] = 583;
	departure_times_AM[2] = 679;


	// Min is smallest difference between input_minutes and departure_minutes
	// Meaning, closet departure time
	// Set min = first index of array
	
	int min_time = 0;
	int closet_departure = 0;
	
	// determine if PM or AM
	if (time_prefix == 'p' || time_prefix == 'P') {
		min_time = input_minutes - departure_times_PM[0]; // initialize min_time by subtracting input_minutes to first element of departure[]
		if (min_time < 0) {
			min_time =  abs(min_time);
			
		}

		// set time_size by subtracting rest of the elements in departure[]
		// find out the smallest between time_size and min_time, then swap.
		for (int i = 1; i < DEPARTURE_PM_LEN; i++) {
			int time_size = input_minutes - departure_times_PM[i];
			
			if (time_size < 0) {
				time_size = abs(time_size);
			}

			if (time_size < min_time) {
				
				closet_departure = i;
				min_time = time_size;
			}


		}
	}
	else  if (time_prefix == 'a' || time_prefix == 'A') {
		min_time = input_minutes - departure_times_AM[0];
		if (min_time < 0) {
			min_time = abs(min_time);
		}

		for (int i = 1; i < DEPARTURE_AM_LEN; i++) {
			int time_size = input_minutes - departure_times_AM[i];
			if (time_size < 0) {
				time_size = abs(time_size);
			}

			if (time_size < min_time) {
				closet_departure = i;
				min_time = time_size;
				
			}


		}

	}

	// closet_departure holds the smallest index in either departure_pm or departure_am
	// each switch case and its textual departure info corresponds to each ordered element in
	// departure_pm and departure_am.
	// Depending on time_prefix, the earilest time will be shown by matching closet_departure with cases.
	if (time_prefix == 'a' || time_prefix == 'A') {
		switch (closet_departure) {
		case 0:
			printf("Closet departure time is 8:00 am, arriving in 10:16 am");
			break;
		case 1:
			printf("Closet departure time is 9:43 am, arriving in 11:52 am");
			break;
		case 2:
			printf("Closet departure time is 11:19 am, arriving in 1:31 pm");
			break;
		default:
			printf("Invalid time");


		}

	}
	else if (time_prefix == 'p' || time_prefix == 'P') {
		switch (closet_departure) {
		case 0:
			printf("Closet departure time is 12:47 pm, arriving in 3:00 pm");
			break;
		case 1:
			printf("Closet departure time is 2:00 pm, arriving in 4:08 pm");
			break;
		case 2:
			printf("Closet departure time is 3:45 pm, arriving in 5:55 pm");
			break;
		case 3:
			printf("Closet departure time is 7:00 pm, arriving in 9:20 pm");
			break;
		case 4:
			printf("Closet departure time is 9:45 pm, arriving in 11:58 pm");
			break;
		default:
			printf("Invalid time");
			break;


		}
	}
	return 0;
}

/**
 * extracts time in text and converts to int
 * stores the values in global vars minutes and hours
 * */
void extract_time(char time[], int length) {
	int stop_here = 0;

	for (int i = 0; i < MAX_TIME_LENGTH; i++) {
		if (time[i] == ':') {
			stop_here = 1;
			if ((time[i + 1] - '0') == 0) {
				minutes = time[i + 2] - '0';
				break;
			}
			else {
				minutes = time[i + 1] - '0';
				minutes *= 10;
				minutes = minutes + (time[i + 2] - '0');
				break;
			}
		}

		if (stop_here == 0) {
			hour = time[i] - '0';
			if (time[i + 1] != ':') {
				hour *= 10;
				hour = hour + (time[i + 1] - '0');
				stop_here = 1;
			}
		}     
	}
}

/**
 * Gets time_prefix 
 * 
 * */
char get_time_prefix(char time[], int length) {

	char time_prefix = ' ';
	
	for (int i = 0; i < length; i++) {
		if (time[i] == 'p' || time[i] == 'P') {
			time_prefix = time[i];
			break;
		}
		if (time[i] == 'a' || time[i] == 'A') {
			time_prefix = time[i];
			break;
		}
	}
	return time_prefix;
}



//    130
// 480 -130 = 350
//   580 - 130 = 450            