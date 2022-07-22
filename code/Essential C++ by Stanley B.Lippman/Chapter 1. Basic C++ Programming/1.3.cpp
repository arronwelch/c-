// 1.3 Writting Expressions

// Arithmetic Operators
// +	addition		a + b
// -	subtraction		a - b
// *	multiplication	a * b
// /	division		a / b
// %	remainder		a % b

// The division of two integer values yields a while number.Any remainder is truncated;there
// is no rounding.The remainder is accessed using the % operator:

// 5 / 3 evaluates to 1 while 5 % 3 evaluates to 2
// 5 / 4 evaluates to 1 while 5 % 4 evaluates to 1
// 5 / 5 evaluates to 1 while 5 % 5 evaluates to 0

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	// string a_string = "these statement are executed many times, with"
	// " a_string representing a different value each time"
	// " and cnt growing by one with each execution ...\n";

	const int line_size = 8;
	int cnt = 1;
	vector<string> a_string = {
		"these","statement", "are", "executed", "many", "times," "with",
		"a_string", "representing", "a", "different", "value", "each", "time",
		"and", "cnt", "growing", "by", "one", "with", "each", "execution", "...\n",
	};

	// these statement are executed many times, with
	// a_string representing a different value each time
	// and cnt growing by one with each execution ...
	while (cnt < a_string.size())
	{
		cout << a_string[cnt]
			 << (cnt % line_size ? ' ' : '\n');
		cnt++;
	}

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
