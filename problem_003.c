#include <stdio.h>
#include <math.h>

/*
 
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?

*/

void problem_003(void){
	long long n = 600851475143;
	int factor = 2;
	int largest_prime_factor = 1;
	int largest_possible_factor = sqrt(n); /* a prime factor of n can't possibly be any larger than sqrt(n), so no need to check any further than that */
	while(n > 1 && factor < largest_possible_factor){
		if(n % factor == 0){
			largest_prime_factor = factor;
			n = n/factor;
			while (n % factor == 0) {
				n = n / factor;
			}			
		}
		factor++;
	}
	printf("%i",largest_prime_factor);
	
	return;
}
