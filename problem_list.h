#ifndef PROBLEM_LIST_H
#define PROBLEM_LIST_H

#include "problem_001.h"

typedef void (*function_pointer)(void);
typedef struct problem_list{
	int problem_id;
	function_pointer problem_function;
} problem_list;

problem_list solved_problems[] = {	
	{1, &problem_001},	
};

#endif

