#include <stdio.h>
#include <math.h>

/*

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

/* Once again the brute force route would technically work, but using some simple algebra this can be done way faster. 
 * Code should be pretty self explanatory. */
 
void problem_006(void){
	int n = 100;
	int sum_of_squares = pow(n*(n+1)/2,2);
	int square_of_sum = (2*pow(n,2) + 3*n + 1) * n/6;
	int difference = sum_of_squares - square_of_sum;
	printf("%i",difference);
	return;
}
