// 3.2.cpp

#include <iostream>		// std::cout
#include <vector>		// std::vector
#include <list>			// std::vector
#include <iterator>		// std::iterator

template <typename IteratorType >
void my_display(IteratorType *first, IteratorType *last, std::ostream &os)
{
	if (!first || !last)
		return;

	for (; first != last; ++first)
		os << *first << ' ';
	os << '\n';
}

template <typename IteratorType, typename elemType>
IteratorType my_find(IteratorType first, IteratorType last,
					const elemType &value)
{
	for (; first != last; ++first)
		if (*first == value)
			return first;

	return last; // Why?!
}

int main(void)
{
	const int ASIZE = 8;
	int ia[ASIZE] = { 1, 1, 2, 3, 5, 8, 13, 21 };
	int search_value;

	my_display(ia, ia+ASIZE, std::cout);

	// initialize the list and vector with the 8 elements of ia
	std::vector<int> ivec(ia, ia+ASIZE);
	std::list<int> ilist(ia, ia+ASIZE);

	search_value = 2;
	int *pia = my_find(ia, ia+ASIZE, search_value);
	if (pia != ia+ASIZE)
		// found ...
		std::cout << search_value << ":found in int array" << '\n';
	else
		std::cout << search_value << ":not found in int array" << '\n';

	search_value = 7;
	std::vector<int>::iterator ivec_iter;
	ivec_iter = my_find(ivec.begin(), ivec.end(), search_value);
	if (ivec_iter != ivec.end())
		// found ...
		std::cout << search_value << ":found in int vector" << '\n';
	else
		std::cout << search_value << ":not found in int vector" << '\n';

	search_value = 21;
	std::list<int>::iterator ilist_iter;
	ilist_iter = my_find(ilist.begin(), ilist.end(), search_value);
	if (ilist_iter != ilist.end())
		// found ...
		std::cout << search_value << ":found in int list" << '\n';
	else
		std::cout << search_value << ":not found in int list" << '\n';

	return 0;
}
