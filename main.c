#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "problem_list.h"

/* prints proper usage of program and exits returning non-zero value */
void fail(char **argv){
	printf("usage: %s <problem number>\n",argv[0]);
	exit(EXIT_FAILURE);
}

/* since atoi is bad this is a custom function which uses strtol to get long from string, checks it's small enough and returns it cast to int */
int intfromstr (char str[]){
	long long_integer = strtol(str,NULL,10);
	assert(INT_MIN >= long_integer <= INT_MAX);
	return (int)long_integer;
}

/* checks if arguments are what we expect or fails */
void check_args(int argc, char **argv){
	if(argc != 2){
		fail(argv);
	}	
	int problem_number = intfromstr(argv[1]);
	if(problem_number <= 0){
		fail(argv);
	}
	return;
}

int main(int argc, char **argv){
	check_args(argc,argv);
	int problem_number = intfromstr(argv[1]);
	int number_of_problems = sizeof(solved_problems)/sizeof(*solved_problems); /* gets */
	int i;
	/* iterate over list of solved problems, and if the input matches a solved problem calls it's corresponding function pointer, see problem_list.h for list of solved problems */
	for(i = 0; i <= number_of_problems-1; i++){
		if(solved_problems[i].problem_id == problem_number){
			printf("Calculating solution for problem number %i...\n", problem_number);
			solved_problems[i].problem_function(); 
			exit(EXIT_SUCCESS);
		}		
	} 
	printf("Problem number %i has not been solved yet.", problem_number);
	return 0;
}
