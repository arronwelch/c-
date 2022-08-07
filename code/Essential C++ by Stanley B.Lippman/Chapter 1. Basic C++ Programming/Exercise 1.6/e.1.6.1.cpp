/* Exercise 1.6 : e.1.6.1.cpp (vector class) */

/*
	Write a program to read in a sequence of integers from standard input.
	Place the values, in turn, in a built-in array and a vector.Iterate over
	the containers to sum the values.Display the sum and average of the
	entered values to standard output.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> ivec;
	int ival = 0;
	int sum = 0;
	int average = 0;
	while (cin >> ival)
			ivec.push_back(ival);

	// we could have calculated the sum as we entered the
	// values, but the idea is to iterate over the vector ...
	for (int ix = 0; ix < ivec.size(); ++ix)
		sum += ivec[ix];

	average = sum / ivec.size();

	cout << "Sum of " << ivec.size()
		 << " elements: " << sum
		 << ". Average: " << average << endl;

	return 0;
}
