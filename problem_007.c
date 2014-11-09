#include <stdio.h>
#include "common.h"

/*
 
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

/* reusing the function is_prime developed for problem 005, this problem is pretty straight forward */

void problem_007(void){
	int n = 10001;
	int i;
	int j = 1;
	for(i = 3; i <= n*n; i += 2){
		if(is_prime(i)){ /* using is_prime from common.c */
			j++;			
		}
		if(j == n){
			printf("%i",i);
			return;
		}
	}
	return;
}
