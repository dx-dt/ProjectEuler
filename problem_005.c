#include <stdio.h>
#include <math.h>
#include <string.h>
#include "common.h"

/*
 
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

/* Initially I took a brute force iterative approach to this problem but I realised soon
 * that the result grew far to quickly. So I switched to an approach based on the fundamental
 * theorem of arithmetic; that all natural numbers either are primes, or the product of a
 * number of primes.*/

/* function to determine if an int is a prime, uses bool type from common.h */
bool is_prime(unsigned int n){
	if(n <= 1){
		return false;
	}
	int i;
	for(i = 2; i*i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
 
void problem_005(void){
	int i;
	int j = 0;
	int n = 20;	
	/* create and array for primes, initialise it to zero and populate it with primes */
	int prime[n-1];
	memset(prime, 0, sizeof(prime));	
	for(i = 2; i <= n-1; i++){
		if(is_prime(i)){
			prime[j] = i;
			j++;
		}
	}
	i = 0;	
	/* calculate the coefficients for each prime using some logarithmic magic and multiply them together */
	int coefficient[n-1];
	int product = 1;
	while(prime[i] != 0){
		coefficient[i] = floor(log(n)/log(prime[i]));		
		product = product * pow(prime[i],coefficient[i]);
		i++;		
	}
	printf("%i",product);
	return;
}
