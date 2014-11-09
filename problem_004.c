#include <stdio.h>
#include "common.h"

/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

/* nested loops, counting downwards, inner loop breaks if product is smaller than largest palindrome so far, otherwise checks if product is palindrome */

void problem_004(void){
	int largest_palindrome = 0;
	int product;
	int j,k;	
	for(j = 999; j >= 100; j--){
		for(k = 999; k >= 100; k--){
			product = j*k;
			if(product <= largest_palindrome){
				break;
			} else if(is_palindrome(product)) { /* function is_palindrome from common.c, takes int returns bool */
				largest_palindrome = product;				
			}
		}
	}
	printf("%i",largest_palindrome);	
	return;
}
