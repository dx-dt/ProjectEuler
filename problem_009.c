#include <stdio.h>
#include <math.h>
#include "common.h"

/*
 
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

/* We start of with some algebraic manipulation to get a as a function of b, and then it's 
 * just a question of iteratively finding the right b (IE, the one that is integer) and then
 * getting the product of a, b and c. */
 
void problem_009(void){
	float n = 1000;
	float a,b;
	for(b = 1; b <= n/2; b++){
		a = ((n*n)/2-(n*b))/(n-b);		
		if(is_integer(a)){
			int product = a*b*sqrt(a*a + b*b);
			printf("%i",product);
			return;
		}
	}
	return;
}
