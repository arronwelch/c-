// 1.3 Writting Expressions

// Arithmetic Operators
// +	addition		a + b
// -	subtraction		a - b
// *	multiplication	a * b
// /	division		a / b
// %	remainder		a % b

// 5 / 3 evaluates to 1 while 5 % 3 evaluates to 2
// 5 / 4 evaluates to 1 while 5 % 4 evaluates to 1
// 5 / 5 evaluates to 1 while 5 % 5 evaluates to 0

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string a_string = "these statement are executed many times, with"
	" a_string representing a different value each time"
	" and cnt growing by one with each execution ...\n";

	const int line_size = 8;
	int cnt = 1;
	
	// these statement are executed many times, with
	// a_string representing a different value each time
	// and cnt growing by one with each execution ...
	cout << a_string
		 << (cnt % line_size ? ' ' : '\n');

	cnt = cnt + 2;
	cnt += 2;	// add 2 to the current value of cnt
	cnt++;	// add 1 to the current value of cnt
	cnt--;	// subtract 1 from the current value of cnt

	int tries = 0;
	cout << "Are you ready for try #"
		 << ++tries << "?\n";

	/* int */tries = 1;
	cout << "Are you ready for try #"
		 << tries++ << "?\n";
}
