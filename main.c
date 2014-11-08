#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef void (*function_pointer)(void);
typedef struct problem_list{
	int problem_id;
	function_pointer problem_function;
} problem_list;

problem_list solved_problems[] = {	
	
};

int number_of_problems = sizeof(solved_problems)/sizeof(*solved_problems);
int i;

void fail(char **argv){
	printf("usage: %s <problem number>\n",argv[0]);
	exit(EXIT_FAILURE);
}

int intfromstr (char str[]){
	long long_integer = strtol(str,NULL,10);
	assert(INT_MIN >= long_integer <= INT_MAX);
	return (int)long_integer;
}

int main(int argc, char **argv){
	
	if(argc != 2){
		fail(argv);
	} 
	
	int problem_number = intfromstr(argv[1]);
	
	if(problem_number <= 0){
		fail(argv);
	}
		
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

