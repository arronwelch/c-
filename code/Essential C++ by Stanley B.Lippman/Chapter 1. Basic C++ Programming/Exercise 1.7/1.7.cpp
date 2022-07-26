/* Exercise 1.7 : 1.7.cpp */

/*
	using your favorite editor, type two or more lines of text into a file.Write a porgram to open the file,
	reading each word into a vector<string> object.Iterate over the vector, displaying it to cout. That
	done, sort the words using the sort() generic algotithm,

	#include <algorithm>
	sort(container.begin(), container.end().

	Then print the sorted words to an output file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<string> seq_text;
	vector<string> sorted_sqe_text;
	string word;
	ifstream infile("1.7.cpp");

	if(! infile)
	{
		cout << "Open file fail!\n";
	}
	else
	{
		while(infile >> word)
			seq_text.push_back(word);
	}

	for(int ix = 0; ix <seq_text.size(); ix++)
		cout << seq_text[ix] << ' ';
	cout << endl;

	sort(seq_text.begin(), seq_text.end());

	cout << "\nNext is sorted text:\n";
	for(int ix = 0; ix <seq_text.size(); ix++)
		cout << seq_text[ix] << ' ';
	cout << endl;

	return 0;
}
