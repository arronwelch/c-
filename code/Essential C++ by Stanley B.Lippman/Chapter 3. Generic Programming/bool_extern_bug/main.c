// mian.c : bool extern usage bug
#include <stdbool.h>
#include <stdio.h>

//extern int b_a;		// this is error
extern bool b_a;
extern void fun_print();

int main()
{
	printf("before:");
	fun_print();
	b_a = false;
	printf("after:");
	fun_print();

	return 0;
}
