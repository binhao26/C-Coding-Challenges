/**
 * Problem set from CS50 lecture 3 - Algorithms
 * A program that mimics a simple plurality election - a candidate wins by majority
 * 
 * https://cs50.harvard.edu/x/2023/psets/3/plurality/
 * */




#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX 9



struct candidate {
	char name;
	int votes;
};

bool vote(char name);
void selection_sort(struct candidate candidates[0], int candidate_count);
void print_winner();

struct candidate candidates[MAX];
int candidate_count = 0;

	int main() {
		
		int voters = 0;
		printf("Enter number of voters: ");
		scanf("%d", &voters);

		printf("Enter number of participants: ");
		scanf("%d", &candidate_count);
		

		// Single letters are used to represent candidate's full name
		candidate_count = 3;
		char t_name;
		printf("Enter name for each candidate\n");
		for (int i = 0; i < candidate_count; i++) {

			printf("Candidate %d: ", i+1);
			scanf(" %c", &t_name);
			candidates[i].name = t_name;

		}

		char voter_choice; // holds candidate name


		// iterate all voters for votes
		for (int i = 0; i < voters; i++) {
			printf("Voter %d\n", i+1);
			scanf(" %c", &voter_choice);

			// vote, and if candidate name is valid, increment his vote by 1
			if (vote(voter_choice)) {
				for (int j = 0; j < candidate_count; j++) {
					if (candidates[j].name == voter_choice) {
						candidates[j].votes = candidates[j].votes + 1;
						break;
					}
				}
			}
			else {
				printf("Invalid candidate name, enter again\n");
				do {
					scanf(" %c", &voter_choice);
				}while(!vote(voter_choice));
			}

		}

		// sort candidates by most votes
		selection_sort(candidates, candidate_count);
		print_winner();

		return 0;
	}

	// check if a candidate name is valid in the election.
	bool vote(char name) {

		for (int i = 0; i < candidate_count; i++) {
			if (candidates[i].name == name) {
				return true;
			}
		}
		return false;

	}

	void print_winner() {
		int largest_vote = candidates[0].votes;
		char winner = candidates[0].name;

		printf("Winners are: ");
		for (int i = 1; i < candidate_count; i++) {
			if (candidates[i].votes == largest_vote) {
				printf(" %c", candidates[i].name);
			}
		}
		printf("%c", winner);
	}

	// sort candidates from most to least votes, the winner has the most votes and no equals, 
	// if two or more candidates shared same largest number of votes, election is tie.
	void selection_sort(struct candidate candidates[], int candidate_count) {
		int i, j;
		int largest, smallest;
		

		char largest_name;
		int largest_index;
		for (i = 0; i < candidate_count; i++) {

			largest = candidates[i].votes;
			largest_name = candidates[i].name;

			largest_index = i;

			for (j = i + 1; j < candidate_count; j++) {

				if (largest < candidates[j].votes) {

					largest = candidates[j].votes;
					largest_name = candidates[j].name;
					largest_index = j;
				}

			}

			candidates[largest_index].name = candidates[i].name;
			candidates[largest_index].votes = candidates[i].votes;

			candidates[i].votes = largest;
			candidates[i].name = largest_name;


		}
	}




