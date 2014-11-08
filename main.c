#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include "problem_list.h"

int number_of_problems = sizeof(solved_problems)/sizeof(*solved_problems); 

/* prints proper usage of program and exits returning non-zero value */
void fail(char **argv){
	printf("usage: %s [-l|--list] <problem number>\n\n  -l, --list\tlist solved problems, with link to problem on projecteuler.net\n",argv[0]);
	exit(EXIT_FAILURE);
}

/* since atoi is bad this is a custom function which uses strtol to get long from string, checks it's small enough and returns it cast to int */
int intfromstr (char str[]){
	long long_integer = strtol(str,NULL,10);
	assert(INT_MIN >= long_integer <= INT_MAX);
	return (int)long_integer;
}

/* pretty selfexplanatory, isn't it? */
void list_solved_problems(void){
	int i;
	printf("\nThe following problems are solved:\n\n");
	for(i = 0; i <= number_of_problems-1; i++){
		int n = solved_problems[i].problem_id;
		printf("Problem number: %i\thttp://projecteuler.net/problem=%i\n",n,n);
	}
	exit(EXIT_SUCCESS);
}

/* checks if arguments are what we expect and redirects or fails */
void check_args(int argc, char **argv){
	if(argc != 2){
		fail(argv);
	}	
	if(strcmp(argv[1],"-l") == 0 || strcmp(argv[1],"--list") == 0){
		list_solved_problems();
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
