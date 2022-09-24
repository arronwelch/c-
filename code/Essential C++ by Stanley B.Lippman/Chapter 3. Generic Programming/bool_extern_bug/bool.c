// bool.c

#include <stdbool.h>
#include <stdio.h>

bool b_a = true;
char c_a = 'a';
char c_b = 'b';
char c_c = 'c';

void fun_print()
{
	printf("%2x %2x %2x %2x\r\n", b_a, c_a, c_b, c_c);
}
