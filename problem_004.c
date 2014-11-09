#include <stdio.h>
#include "common.h"

/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

/* function to reverse the order of digits in int using some fancy base 10 arithmetic magic */
int reverse(int n){
	int r = 0;
	while(n > 0){
		r = 10*r + n % 10;
		n = n/10;
	}
	return r;
}

/* function to check if an int is a palindrome, no more no less */
bool is_palindrome(int n){
	int m = reverse(n);
	if(m == n){
		return true;
	} else {
		return false;
	}	
}

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
			} else if(is_palindrome(product)) {
				largest_palindrome = product;				
			}
		}
	}
	printf("%i",largest_palindrome);	
	return;
}
