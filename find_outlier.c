/**
 * A coding problem from code war - Find the parity outlier
 * 
 * "You are given an array (which will have a length of at least 3,
 *  but could be very large) containing integers. 
 * The array is either entirely comprised of odd integers or 
 * entirely comprised of even integers except for a single integer N. 
 * Write a method that takes the array as an argument and returns this "outlier" N."
 * 
 * https://www.codewars.com/kata/5526fc09a1bbd946250002dc
 * */




#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <String.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


int find_even_or_odd(int even_counts, int odd_counts);
int odd_or_even(int n);
int find_outliner(int nums[], int length);


int main(int argc, char *argv[])
 {

 	int nums[] = {4, 2, 8, 24, -3, 20, 18};
 	//            0  0   1
 	//            1  0   0
 	// int even_count
 	// int odd_count  // if one of these vars occur two times, then it is a respective even or odd array

 	// first compare current_index against previous_index, if there is difference, proceed to next procedure. othweise continue the loop
 	// next procedure: count the occurences of both 1-0 values returned by func
 	//determine if its even or odd ()
 	// second loop begins at previous up till current_index + 1; find the even or odd, then return it.

 	int outlin = find_outliner(nums, num_length);

 	printf("outliner is %d", outlin);

 	
	return 0;



}

int find_outliner(int nums[], int num_length) {
	//starts the loop at second element
	// compare
	int previous_index = 0;
	int current_index = 1;

	int even_counts, odd_counts = 0;

	int outliner;

	

	/**
	 * For the first three elements beginning at start of num[i] till the end
	 *  find out between the three of these numbers if more is even or odd
	 * if two of these numbers are odd, then num[i] is likely entirely comprised of even numbers and vice visa
	 * */
	for (; current_index < num_length - 2; current_index++) {
		if (odd_or_even(nums[previous_index]) != odd_or_even(nums[current_index])) {
			if (odd_or_even(nums[previous_index]) == 0) {
				even_counts = even_counts + 1;
			}
			else {
				odd_counts = odd_counts + 1;
			}
			if (odd_or_even(nums[current_index]) == 0) {
				even_counts = even_counts + 1;
			}
			else {
				odd_counts = odd_counts + 1;
			}
			if (odd_or_even(nums[current_index + 1]) == 0) {
				even_counts = even_counts + 1;
			}
			else {
				odd_counts = odd_counts + 1;
			}

			// n will either be 1 - meaning num[i] entirely comprised of even numbers
			// or 0 - num[i] entirely comprised of odd numbers
			// for the current three elements, if one of them matches n, then it is the outlier.
			// 
			int n = find_even_or_odd(even_counts, odd_counts);
			for (int i = previous_index; i <= current_index + 1; i++) {
				if (odd_or_even(nums[i]) == n) {
					return nums[i];

				}
			}
		}
		

	}


}

/**
 * Determine if a given integer is odd or even
 * if odd, return 1
 * if even return 0
 * */
int odd_or_even(int n) {
	n = abs(n);
	if (n % 2 == 0) {
		return 0;
	}
	return 1;
}

int sum(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n + (sum(n - 1));
	}
}

/**
 * Find if there are more even numbers or odd numbers
 * 
 * */
int find_even_or_odd(int even_counts, int odd_counts) {
	if (even_counts > odd_counts) {
		return 1;
	}
	else if (odd_counts > even_counts) {
		return 0;
	}
}
