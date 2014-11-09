#include <stdio.h>
#include "common.h"

/* simple recursive function for getting the n:th fibonacci number */
int fibonacci(int n){
	if(n == 0){
		return 0;
	} else if(n == 1){
		return 1;
	} else {
		return (fibonacci(n-2)+fibonacci(n-1));		
	}
}

/* function to reverse the order of digits in int using some fancy base 10 arithmetic magic */
int reverse(int n){
	int r = 0;
	while(n > 0){
		r = 10*r + n % 10;
		n = n/10;
	}
	return r;
}

/* function to check if an int is a palindrome */
bool is_palindrome(int n){
	int m = reverse(n);
	if(m == n){
		return true;
	} else {
		return false;
	}	
}

/* function to determine if an int is a prime */
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
