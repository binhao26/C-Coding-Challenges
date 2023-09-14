#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
// 0 1 2 3 4 
// 5 2 0 2 4

void merge(int left[], int left_len, int right[], int right_len, int numbers[]);
void mergesort(int numbers[], int num_length);

int main() {
	int num_len = 11;
	int numbers[] = {2, 3, 1, 9, 0, 4, 2, 5, 3, 8, 7};


	mergesort(numbers, num_len);

	for (int i = 0; i < num_len; i++) {
		printf(" %d", numbers[i]);
	}

	



	return 0;
}

void merge(food_menu left[], int left_len, food_menu right[], int right_len, food_menu order_list[]) {
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < left_len && j < right_len) {
		if (left[i].order_position <= right[j].order_position) {
			order_list[k] = left[i];
			i = i + 1;
		}
		else {
			order_list[k] = right[j];
			j = j + 1;
		}
		k = k + 1;
	}

	while (i < left_len) {
		order_list[k] = left[i];
		i = i + 1;
		k = k + 1;
	}

	while (j < right_len) {
		order_list[k] = right[j];
		j = j + 1;
		k = k + 1;
	}
}


void mergesort(food_menu order_list[], int new_or_counter) {
	int mid_len = 0;
	int right_len = 0;
	int left_len = 0;
	if (new_or_counter < 2) return;
	
	mid_len = num_length / 2;
	left_len = mid_len;
	right_len = num_length - mid_len;
	
	food_menu left[left_len];
	food_menu right[right_len];

	for (int i = 0; i < mid_len; i++) {
		left[i] = order_list[i];
		
	}

	for (int j = mid_len; j < new_or_counter; j++) {
		right[j - mid_len] = order_list[j];
		
	}

	mergesort(left, left_len);
	mergesort(right, right_len);
	merge(left, left_len, right, right_len, order_list);





}

