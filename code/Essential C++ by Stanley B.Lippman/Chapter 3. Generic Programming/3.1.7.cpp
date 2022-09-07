// 3.1.7.cpp

#include <iostream>
#include <vector>

using namespace std;

template <typename elemType>
const elemType* my_find(const elemType* first,
						const elemType* last,
						const elemType &value)
{
	if (! first || ! last)
		return 0;

	for(; first != last; ++first)
		if(*first == value)
			return first;

	return 0;
}

template <typename elemType>
inline const elemType* my_begin(const vector<elemType> &vec)
	{ return (vec.empty() ? 0 : &vec[0]); }

template <typename elemType>
inline const elemType* my_end(const vector<elemType> &vec)
	{ return (vec.empty() ? 0 : &vec[vec.size()]); }

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
		cout << "svec is not empty!" << endl;
		cout << "ok, call my_find()" << endl;

		// A vector also holds its elements in a contiguous area of memory,
		// so we can pass my_find() a begin/end pair of addresses in the same way
		// as we do for the built-in array, except in one case.
		// Unlike an array, a vector can be empty.
		cout << *my_find(&svec[0], &svec[svec.size()], search_value) << endl;
	}
	else
		cout << "an empty vector" << endl;

	search_value = "the third";
	cout << *my_find( my_begin(svec), my_end(svec), search_value) << endl;
	// find() begin() end() all have same keyname in lib header file!!!

	return 0;
}
