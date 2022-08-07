/* Exercise 1.7 : e.1.7.cpp */

/*
Using your favorite editor, type two or more lines of text into a file.
Write a porgram to open the file,reading each word into a vector<string> object.
Iterate over the vector, displaying it to cout.
That done, sort the words using the sort() generic algotithm,

	#include <algorithm>
	sort(container.begin(), container.end());

Then print the sorted words to an output file.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	// ifstream in_file("C:\\My Documents\\test.txt");
	ifstream in_file("text.txt");
	if(! in_file)
		{ cerr << "Oops! unable to open input file\n"; return -1; }

	// ofstream out_file("C:\\My Documents\\text.sort");
	ofstream out_file("text.sort");
	if(! out_file)
		{ cerr << "Oops! unable to open input file\n"; return -2; }

	string word;
	vector< string > text;
	while (in_file >> word)
		text.push_back(word);

	int ix;
	cout << "unsorted text: \n";

	for(ix = 0; ix <text.size(); ++ix)
		cout << text[ix] << ' ';
	cout << endl;

	sort(text.begin(), text.end());

	out_file << "sorted text: \n";
	for(ix = 0; ix < text.size(); ++ix)
		out_file << text[ix] << ' ';
	out_file << endl;

	return 0;
}
