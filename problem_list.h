#ifndef PROBLEM_LIST_H
#define PROBLEM_LIST_H

/* list of problem functions */
void problem_001(void);
void problem_002(void);
void problem_003(void);
void problem_004(void);

/* defines a function pointer to problem functions, and a struct for associating problem numbers with their problem functions */
typedef void (*function_pointer)(void);
typedef struct problem_list{
	int problem_id;
	function_pointer problem_function;
} problem_list;

/* create an array of the above defined struct and populate it with the solved problems numbers and corresponding function pointers*/
problem_list solved_problems[] = {	
	{  1, &problem_001},
	{  2, &problem_002},
	{  3, &problem_003},
	{  4, &problem_004},
};

#endif

