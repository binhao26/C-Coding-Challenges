/**
 * This is a codewar problem set
 * The problem is to organize a customer's order to follow the menu items sequence from menu
 * */


#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/**
 * Increase the array size by 1, char orig[6];.
Add a null -terminator in the end. After the loop body, add orig[i] = '\0';
 * char name[5] = "hello" // only fit the letter but no space for null terminated char
 * hence, the reason some random symbols appear at the end.
 * solution: increase name ssize by 1
 * ----%s with printf() expects a pointer to a string, that is, pointer to the initial element of a null terminated character array. Your array is not null terminated.

Thus, in search of the terminating null character, printf() goes out of bound, and subsequently, invokes undefined behavior.----
 * */

#define ORDER_MAX_LENGTH 100
#define MAX_ITEM_LENGTH 10
#define MENU_LENGTH 7



//char *new_orders[ORDER_MAX_LENGTH];


typedef struct {
	char *cool_order;
	int order_position;
}
food_menu;

food_menu order_list[ORDER_MAX_LENGTH];
static int new_or_counter = 0;

char *int_to_char(int n);
char *get_add();
bool assign_orders(char *single_order, int single_length, char *new_menu[]);
char *extract_item(char single_order[], int head, int tail);
void merge(food_menu left[], int left_len, food_menu right[], int right_len, food_menu order_list[]);
void mergesort(food_menu order_list[], int new_or_counter);


int main() {
	
	// look at the items on the menu 
	// Starting at the top
	// for the current menu item
	// look at it and search through the input string
	// if found it appear in the input string
	// put that menu item in the new order list, first comes first places

	//Input MilkshakeSteakBurgerSteakHotdog
	//      012345678910111212
	// tail = 5, head = tail - counter

	// MENU: Burger Milkshake Hotdog Cheesecake Steak Chips Pizza 

	// have to keep looping until input is over
	// use strcmp

	// i start at 0, if word_length = 6, range 0-6
	// if not a complete word, move to next word in the menu
	// if is a word, find the right match
	// if matched, update i start at 7-n

	// use switch is an option

	/**
	 * oh shiet, this work!!!!!!
	 * check the difference between pointer array string vs struct array string
	 * 
	 * */
	char *new_menu[MENU_LENGTH];
	new_menu[0] = "pizza";
	new_menu[1] = "chips";
	new_menu[2] = "steak";
	new_menu[3] = "hotdog";
	new_menu[4] = "burger";
	new_menu[5] = "milkshake";
	new_menu[6] = "cheesecake";

	// to-do: in assign_orders, tweak new_menu to be a struct and keep track of index locations in new_menu
	// where each new_order items is found.
	// then use this info to determine the correct ordering of each new_order items.



	
	int c;
	
	
	
	int single_length = 0;
	char single_order[ORDER_MAX_LENGTH];
	


	printf("Please place your order: ");
	while((c = getchar()) != EOF) {

		if (c == '\n') break;
		single_order[single_length] = c;
		single_length = single_length + 1;

	}

		//Input MilkshakeSteakBurgerSteakHotdog
	//      012345678910111212
	// tail = 5, head = tail - counter
/**
 * use counter to track how many chars read correspond 
 * to the numbers of char composed of each menu items
 * in new_menu.
 * head and tail are used for tracking the initial and ending char corresponding
 * to menu items's length, in turns aid in extracting the correct string
 * 
 * */
	int head = 0;
	int tail = 0;
	int counter = 0;
	char *holder_string;

	for (int i = 0; i < single_length; i++) {
		tail = i;
		counter = counter + 1;
		//counter is relative to i iterations, if it matches switch cases, meaning a
		// correct length string might be the same to one of menu items
		switch(counter) {

			case 5:
				head = tail - (counter - 1);
				holder_string = extract_item(single_order, head, tail); // based off head and tail, extract chars in between head to tail.
				// if a correct string has extracted, reset counter and start counting up again.
				if (assign_orders(holder_string, counter, new_menu) == true) {
					counter = 0;
					head = 0;
				}
			break;
			case 6:
				head = tail - (counter - 1);
				holder_string = extract_item(single_order, head, tail);
				if (assign_orders(holder_string, counter, new_menu) == true) {
					counter = 0;
					head = 0;
				}
			break;
			case 9:
				head = tail - (counter - 1);
				holder_string = extract_item(single_order, head, tail);
				if (assign_orders(holder_string, counter, new_menu) == true) {
					counter = 0;
					head = 0;	
				}
			break;
			case 10:
				head = tail - (counter - 1);
				holder_string = extract_item(single_order, head, tail);
				if (assign_orders(holder_string, counter, new_menu) == true) {
					counter = 0;
					head = 0;
				}
			break;

			default:
			
		}
			
	}

	mergesort(order_list, new_or_counter);

	for (int i = 0; i < new_or_counter; i++) {
		printf("+++order is %s ++++\n", order_list[i].cool_order);
		printf("+++order %d position is %d ++++\n", i, order_list[i].order_position);
	}

	return 0;
		
}

//if extracted string matches one of menu items, return true
bool assign_orders(char *single_order, int single_length, char *new_menu[]) {
	printf("holder_string is %s\n", single_order);
	char cleaned_order[single_length];
	for (int i = 0; i < single_length; i++) {
		cleaned_order[i] = *(single_order + i);
	}
	printf("cleaned_order is %s\n", cleaned_order);

	for (int i = 0; i < MENU_LENGTH; i++) {
		printf("food_menu[%d] is %s\n", i, new_menu[i]);
		if (strcmp(cleaned_order, new_menu[i]) == 0) {
			printf("assign_orders 's %s\n", single_order);
			order_list[new_or_counter].cool_order = new_menu[i];
			order_list[new_or_counter].order_position = i;
			new_or_counter = new_or_counter + 1;
			return true;
		} 
	}
	
	return false;
}

// extract string based on its length starting from head index , end at tail index
char *extract_item(char single_order[], int head, int tail) {
	static char single_item[MAX_ITEM_LENGTH]; // something wrong when assigning the string into single_item
	// it gives hotdogohake instead of hotdog

	for (int i = 0; i < MAX_ITEM_LENGTH; i++) {
		single_item[i] = ' ';
	}
	
	int counter = 0;
	for (int i = head; i <= tail; i++) {
		single_item[counter] = single_order[i];
		printf("-----%c----\n", single_item[counter]);
		counter = counter + 1;
	}
	printf("extract's single_item is %s\n", single_item);
	return single_item;
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
	
	mid_len = new_or_counter / 2;
	left_len = mid_len;
	right_len = new_or_counter - mid_len;
	
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




