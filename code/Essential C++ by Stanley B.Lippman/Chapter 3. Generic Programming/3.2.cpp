// 3.2.2.cpp

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

template <typename IteratorType >
void my_display(IteratorType *first, IteratorType *last, ostream &os)
{
	if (!first || !last)
		return;

	for (; first != last; ++first)
		os << *first << ' ';
	os << endl;
}

template <typename IteratorType, typename elemType>
IteratorType my_find(IteratorType first, IteratorType last,
					const elemType &value)
{
	for (; first != last; ++first)
		if (value == *first)
			return first;

	return last; // Why?!
}

int main(void)
{
	const int asize = 8;
	int ia[asize] = { 1, 1, 2, 3, 5, 8, 13, 21 };
	int search_value;

	my_display(ia, ia+asize, cout);

	// initialize the list and vector with the 8 elements of ia
	vector<int> ivec(ia, ia+asize);
	list<int> ilist(ia, ia+asize);

	search_value = 2;
	int *pia = my_find(ia, ia+asize, search_value);
	if (pia != ia+asize)
		// found ...
		cout << search_value << ":found in int array" << endl;
	else
		cout << search_value << ":not found in int array" << endl;

	search_value = 7;
	vector<int>::iterator ivec_iter;
	ivec_iter = my_find(ivec.begin(), ivec.end(), search_value);
	if (ivec_iter != ivec.end())
		// found ...
		cout << search_value << ":found in int vector" << endl;
	else
		cout << search_value << ":not found in int vector" << endl;

	search_value = 21;
	list<int>::iterator ilist_iter;
	ilist_iter = my_find(ilist.begin(), ilist.end(), search_value);
	if (ilist_iter != ilist.end())
		// found ...
		cout << search_value << ":found in int list" << endl;
	else
		cout << search_value << ":not found in int list" << endl;

	return 0;
}
