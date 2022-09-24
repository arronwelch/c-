/* Exercise 3.4 */

/*
Write a program to read a sequence of integer numbers from standard input using an
istream_iterator. Write the odd numbers into one file using an ostream_iterator. Each value
should be separated by a space. Write the even numbers into a second file,
also using an ostream_iterator. Each of these values should be placed on a sepatate line.
*/

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;

class EvenNum
{
public:
	bool operator()(int num)
	{
		return num % 2 ? false : true;
	}
};

int main(int argc, char *argv[])
{
	ofstream writeOddFile("TestFile_3.4.odd");
	ofstream writeEvenFile("TestFile_3.4.even");
	if (!writeOddFile.is_open() || !writeEvenFile.is_open())
	{
		cerr << "Sorry, the file fails to read!" << endl;
		return -1;
	}

	vector<int> vecInput;
	cout << "Please enter some numbers: ";
	istream_iterator<int> inItr(cin), eos;
	copy(inItr, eos, back_inserter(vecInput));
	vector<int>::iterator itr = partition(vecInput.begin(), vecInput.end(), EvenNum());
	ostream_iterator<int> oddItr(writeOddFile, " "), evenItr(writeEvenFile, "\n");
	copy(vecInput.begin(), itr, evenItr);
	copy(itr, vecInput.end(), oddItr);

	return 0;
}

/* Ctrl-D to tirgger EOF */
