/* Exercise 3.2 */

/*
Read in a text file - it can be the same one as in Exercise 3.1 - storing it in a vector. Sort
the vector by the length of the string. Define a function object to pass to sort(); it should
accept two strings and return true if the first string is shorter than the second. Print the 
sorted vector.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;
using std::ifstream;

bool shorter(string &str1, string &str2)
{
	return str1.size() < str2.size();
}

int main(int argc, char *argv[])
{
	ifstream in_file("TestFile_3.2.txt");
	if ( !in_file.is_open() )
	{
		cout << "!!unable open \"TestFile_3.2.txt\" file!\n";
		return -1;
	}

	string tword;
	vector<string> svec;
	while(in_file >> tword)
		svec.push_back(tword);

	sort(svec.begin(), svec.end(), shorter);

	for(vector<string>::iterator it= svec.begin(), endVec = svec.end(); it != endVec; ++it)
		cout << (*it).size() << '\t' << *it << '\n';

	return 0;
}
