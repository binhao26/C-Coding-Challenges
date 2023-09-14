/**
 * This is a codewar problem set - Growing plant
 * https://www.codewars.com/kata/58941fec8afa3618c9000184
 * */


#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


#define SENTENCE_MAX_LENGTH 100

int main() {
	/**
	 * Each day a plant is growing by upSpeed meters. 
	 * Each night that plant's height decreases by 
	 * downSpeed meters due to the lack of sun heat. 
	 * Initially, plant is 0 meters tall. 
	 * We plant the seed at the beginning of a day. 
	 * We want to know when the height of the plant will reach a certain level.
	 * 
	 * */

	int up_speed, down_speed, desired_height, current_height = 0;
	int day_night = 0;

	printf("Enter up speed: ");
	scanf("%d", &up_speed);
	while(up_speed < 5 || up_speed > 100) {
		printf("Please enter up speed within 5-100: ");
		scanf("%d", &up_speed);
	}

	printf("Enter down speed: ");
	scanf("%d", &down_speed);
	while(down_speed < 2 || down_speed > up_speed) {
		printf("Please enter down speed within 2-upspeed: ");
		scanf("%d", &down_speed);
	}

	printf("Enter desired height: ");
	scanf("%d", &desired_height);
	while(desired_height < 4 || desired_height > 1000) {
		printf("Please enter down speed within 2-upspeed: ");
		scanf("%d", &down_speed);
	}

	if (up_speed > desired_height) {
		printf("After day 1 --> %d", up_speed);
		return 0;
	}

	bool still_growing = true;
	while (still_growing) {
		day_night = day_night + 1;
		current_height = current_height + up_speed;
		printf("After day %d --> %d\n", day_night, current_height);
		if (current_height == desired_height) {
			break;
			still_growing = false;
		}
		current_height = current_height - down_speed;
		printf("After night %d --> %d\n", day_night, current_height);
		if (current_height == desired_height) {
			break;
			still_growing = false;
		}
	}









	return 0;
}



