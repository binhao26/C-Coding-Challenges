/**
 * Problem set from CS50 lecture 3 - Algorithm
 * "The Tideman voting method (also known as “ranked pairs”) is 
 * a ranked-choice voting method that’s guaranteed to produce the Condorcet winner of the election if one exists."
 * 
 * "https://cs50.harvard.edu/x/2023/psets/3/tideman/"
 * */





#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
char candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; // containes a pair of candidates where one is preferred over another

int pair_count;
int candidate_count;



bool vote(int rank, char name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void bubble_sort(pair pairs[], int pair_count);
void lock_pairs(void);
void print_winner(void);


	int main() {

		char candidate_name; // candidate name represents by a single letter
		printf("enter candidate name: ");

		int input;
		candidate_count = 0;
		int word_length = 0;
		while ((input = getchar()) != '\n') {
			if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
				
				candidates[candidate_count] = input;
				candidate_count++;

				
			}
			else if (input - '0' >= 0 && input - '0' <= 9) {
				printf("Number not allowed, try again");
				break;
			}
		}

		// prints all candidate names
		for (int i = 0; i < candidate_count; i++) {
			printf("%c", candidates[i]);
		}
		

		int voters = 0;
		printf("Enter number of voters: ");
		scanf("%d", &voters);

		
		int ranks[candidate_count]; // each index in ranks[] represents the respective candidate index in candidates[]
		bool valid_candidate = true; // the elements in ranks[] represents candidate rankings 0 to candidate_len: 0 == rank 1, 1 == rank 2...
		candidate_name = ' ';
		// iterate all voters for their votes and prints their choices
		for (int i = 0; i < voters; i++) {

			for (int j = 0; j < candidate_count && valid_candidate; j++) {
				printf("Rank %d: ", j+1);
				scanf(" %c", &candidate_name);

				if (!vote(j, candidate_name, ranks)) {
					printf("Invalid candidate, try again!");
					valid_candidate = false;
					break;
				}

			}
			record_preferences(ranks); // record each voter's preferences
		}


		add_pairs(); 

		for (int i = 0; i < candidate_count; i++) {
			for (int j = 0; j < candidate_count; j++) {
				printf("preferences[%d][%d] is %d\n", i, j, preferences[i][j]);
			}
		}

		bubble_sort(pairs, pair_count); // sort pairs by strongest preferences

		for (int i = 0; i < pair_count; i++) {
			printf("Pairs[%d] Win: %d  Lose: %d\n", i, pairs[i].winner, pairs[i].loser);
		}

		lock_pairs();

		for (int i = 0; i < candidate_count; i++) {
			for (int j =  0; j < candidate_count; j++) {
				printf("locked[%d][%d] is %d\n", i, j, locked[i][j]);
			}
		}

		print_winner();

		return 0;
	}

	// rank[0] = 1 - 1 = bob, bob is 0: first preference
	// CANDIDIATE COUNT IS 0, NOT WORKING
	bool vote(int rank, char name, int ranks[]) {
		
		for (int i = 0; i < candidate_count; i++) {
			
			if (name == candidates[i]) {
				ranks[rank] = i;
				return true;
			}
		}
		return false;
	}
	//       1          0         2
	// ranks[0] > ranks[1] > ranks[2]
	void record_preferences(int ranks[]) {
		for (int i = 0; i < candidate_count - 1; i++) {
		
			for (int j = i + 1; j < candidate_count; j++) {
				
				preferences[ranks[i]][ranks[j]] = preferences[ranks[i]][ranks[j]] + 1;
				
			}
		}
	}

	/**
	 * add_pair is wrong, in the case of A Vs B, should also include A->C->B, not only A->B->C
	 * too hard, maybe the problem laid in when recording preferences when taking records from ranks
	 * 
	 * 
	 */
	void add_pairs(void) {
		pair_count = 0;
		for (int i = 0; i < candidate_count; i++) {

			for (int j = 0; j < candidate_count; j++) {
				if (preferences[i][j] > preferences[j][i]) {
					pairs[pair_count].winner = i;
					pairs[pair_count].loser = j;
					pair_count++;
				}
			}
		}
	}

	/**
	 * Sort the pairs array in decreasing order of strength of victory, 
	 * where strength of victory is defined to be the number of voters 
	 * who prefer the preferred candidate. 
	 * If multiple pairs have the same strength of victory, 
	 * then the order does not matter.
	 * 
	 * */
	void bubble_sort(pair pairs[], int pair_count) {
		int counter = 0;
		int tem_w, temp_l = 0;
		bool no_swap;

		while(counter < pair_count) {
			no_swap = false;
			for (int i = 0; i < pair_count - 1; i++) {
				if (preferences[pairs[i].winner][pairs[i].loser] > preferences[pairs[i+1].winner][pairs[i+1].loser]) {
					tem_w = pairs[i].winner;
					temp_l = pairs[i].loser;
					pairs[i].winner = pairs[i+1].winner;
					pairs[i].loser = pairs[i+1].loser;
					pairs[i+1].winner = tem_w;
					pairs[i+1].loser = temp_l;
					no_swap = true;
				}
			}

			if (!no_swap) break; // terminate loop early if no more elements to swap

			counter++;
		}
	}

	/**
	 * The function should create the locked graph, 
	 * adding all edges in decreasing order of victory 
	 * strength so long as the edge would not create a cycle.
	 * 
	 * */
	void lock_pairs(void) {
		// ADD last two pairs to locked, since it has no effect on creating circle, a circle needs at least 3 pairs to form
		locked[pairs[pair_count - 1].winner][pairs[pair_count - 1].loser] = true;
		locked[pairs[pair_count - 2].winner][pairs[pair_count - 2].loser] = true;
		bool circle_checker[2] = {false}; // 0 = win, 1 = lose, if both == true,means circle

		int i = pair_count - 3; // set i at location after the first two last pairs added to locked
		int checking_win, checking_lose;

		// main loop start right at location after last two pairs added to locked
		for (; i >= 0; i--) {
			checking_win = pairs[i].winner;
			checking_lose = pairs[i].loser;
			circle_checker[0] = false;
			circle_checker[1] = false;

			//check if current pair's winner value appear in loser index of locked pairs, do the same for current pair's loser 
			for (int j = pair_count - 1; j > i; j--) {
				if (pairs[j].winner == checking_lose) {
					circle_checker[0] = true;
				}
				if (pairs[j].loser == checking_win) {
					circle_checker[1] = true;
				}
			}

			// if at least one of circle_checker's value == false, means no circle.
			for (int k = 0; k < 2; k++) {
				if (circle_checker[k] == false) {
					locked[checking_win][checking_lose] = true;
				}
			}

		}



	}

	/**
	 * The function should print out the name of the candidate who is the source of the graph.
	 *  Which is the winner
	 * 
	 * */
	void print_winner(void) {
		pair sorted_lock_pairs[MAX]; // NEW pair array to store all the pairs present in graph
		int lock_pair_count = 0;

		// store pairs present in graph
		for (int i = 0; i < candidate_count; i++) {

			for (int j = 0; j < candidate_count; j++) {
				if (locked[i][j]) {
					sorted_lock_pairs[lock_pair_count].winner = i;
					sorted_lock_pairs[lock_pair_count].loser = j;
					lock_pair_count++;
				}
			}
		}
		
		bool winner_found;

		// find the source pair thus the winner
		for (int i = 0; i < lock_pair_count; i++) {
			winner_found = true;

			for (int j = i + 1; j < lock_pair_count; j++) {
				if (sorted_lock_pairs[i].winner == sorted_lock_pairs[j].loser) {
					winner_found = false;
				}
			}

			if (winner_found) {
				printf("Candidate %c is the winner!\n", candidates[sorted_lock_pairs[i].winner]);
				break;
			}
		}
	}
