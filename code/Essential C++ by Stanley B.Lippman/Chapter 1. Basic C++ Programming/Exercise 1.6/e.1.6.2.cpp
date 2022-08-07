/* Exercise 1.6 : e.1.6.2.cpp (C-Style: built-in array) */

/*
	Write a program to read in a sequence of integers from standard input.
	Place the values, in turn, in a built-in array and a vector.Iterate over
	the containers to sum the values.Display the sum and average of the
	entered values to standard output.
*/

#include <iostream>
using namespace std;

int main(void)
{
	const int array_size = 128;
	int ia[array_size];
	int ival, icnt = 0;
	int sum = 0;
	int average = 0;

	while (cin >> ival && icnt < array_size)
		ia[icnt++] = ival;

	// we could have calculated the sum as we entered the
	// values, but the idea is to iterate over the vector ...
	for (int ix = 0; ix < icnt; ++ix)
		sum += ia[ix];

	average = sum / icnt;

	cout << "Sum of " << icnt
		 << " elements: " << sum
		 << ". Average: " << average << endl;

	return 0;
}
