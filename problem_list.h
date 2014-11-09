#ifndef PROBLEM_LIST_H
#define PROBLEM_LIST_H

/* list of problem functions */
void problem_001(void);
void problem_002(void);
void problem_003(void);
void problem_004(void);
void problem_005(void);
void problem_006(void);
void problem_007(void);
void problem_008(void);

/* create an array of the problem_list struct from common.h and populate it with the solved problems numbers and corresponding function pointers*/
problem_list solved_problems[] = {	
	{  1, &problem_001},
	{  2, &problem_002},
	{  3, &problem_003},
	{  4, &problem_004},
	{  5, &problem_005},
	{  6, &problem_006},
	{  7, &problem_007},
	{  8, &problem_008},
};

#endif
