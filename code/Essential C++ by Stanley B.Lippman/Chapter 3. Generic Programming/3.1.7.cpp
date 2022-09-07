// 3.1.7.cpp

#include <iostream>
#include <vector>

using namespace std;

template <typename elemType>
const elemType* my_find(const elemType* first,
						cosnt elemType* second,
						const elemType &value)
{
	if (! 
}

template <typename elemType>
inline elemType* begin(const vector<elemType> &vec)
	{ return vec.empty() ? 0 : &vec[0]; }

template <typename elemType>
inline elemType* end(const vector<elemType> &vec)
	{ return vec.empty() ? 0 : &vec[vec.size()] }

int main(void)
{
	// defines an empty vector of string elements.
	vector<string> svec;
	string search_value;

	svec.push_back("the first");
	svec.push_back("the second");
	svec.push_back("the third");
	search_value = "the second";

	if(! svec.empty()) // ... ok, call my_find()
	{
		cout << "ok, call my_find()" << endl;
		cout << my_find(&vec[0], &vec[vec.size()], search_value) << endl;
	}
	else
		cout << "an empty vector" << endl;

	return 0;
}
