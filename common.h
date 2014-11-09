#ifndef COMMON_H
#define COMMON_H

/* ANSI C doesn't have a bool type, so let's invent the wheel again */
typedef enum {false = 0, true = 1} bool;

/* defines a function pointer to problem functions, and a struct for associating problem numbers with their problem functions */
typedef void (*function_pointer)(void);
typedef struct problem_list{
	int problem_id;
	function_pointer problem_function;
} problem_list;

/* list of common functions which is, or mighe be, used by more than one problem */

int fibonacci(int);
int reverse(int);
bool is_palindrome(int);
bool is_prime(unsigned int);

#endif
