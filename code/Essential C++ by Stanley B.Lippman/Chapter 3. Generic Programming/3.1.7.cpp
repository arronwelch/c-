// 3.1.7.cpp

#include <iostream>		// std::cout
#include <vector>		// std::vector
#include <string>		// std::string

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
inline const elemType* my_begin(const std::vector<elemType> &vec)
	{ return (vec.empty() ? 0 : &vec[0]); }

template <typename elemType>
inline const elemType* my_end(const std::vector<elemType> &vec)
	{ return (vec.empty() ? 0 : &vec[vec.size()]); }

int main(void)
{
	// defines an empty std::vector of std::string elements.
	std::vector<std::string> svec;
	std::string search_value;

	svec.push_back("the first");
	svec.push_back("the second");
	svec.push_back("the third");

	search_value = "the second";
	if(! svec.empty()) // ... ok, call my_find()
	{
		std::cout << "svec is not empty!" << '\n';
		std::cout << "ok, call my_find()" << '\n';

		// A std::vector also holds its elements in a contiguous area of memory,
		// so we can pass my_find() a begin/end pair of addresses in the same way
		// as we do for the built-in array, except in one case.
		// Unlike an array, a std::vector can be empty.
		std::cout << *my_find(&svec[0], &svec[svec.size()], search_value) << '\n';
	}
	else
		std::cout << "an empty std::vector" << '\n';

	search_value = "the third";
	std::cout << *my_find( my_begin(svec), my_end(svec), search_value) << '\n';
	// find() begin() end() all have same keyname in lib header file!!!

	return 0;
}
