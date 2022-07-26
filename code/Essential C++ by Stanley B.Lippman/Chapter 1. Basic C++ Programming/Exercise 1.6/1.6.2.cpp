/* Exercise 1.6 : 1.6.2.cpp */

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
	const int seq_size = 100;
	// int seq_data[seq_size];
	vector<int> seq_data(seq_size);

	int index = 0;
	int sum = 0;
	float avg = 0;

	cout << "Please enter the sequence, separately by whitespace:\n";
	while(index < seq_size && cin >> seq_data[index] && seq_data[index] != -1)
		sum += seq_data[index++];

	avg = sum*1.0 / index;

	cout << "The sum of sequence is " << sum 
		 << "\nThe average of sequence is " << avg << endl;

	return 0;
}
