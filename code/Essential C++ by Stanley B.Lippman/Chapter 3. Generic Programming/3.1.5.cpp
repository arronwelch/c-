// 3.1.5.cpp

#include <iostream>
#include <cstdio>
using namespace std;

template <typename elemType>
const elemType* my_find(const elemType *first,
						const elemType *last,
						const elemType &value)
{
	if (!first || !last)
		return 0;

	// while first does not equal last
	// compare value with element addressed by first
	// if the two are equal, return first
	// otherwise, increment first to address next element

	for (; first != last; ++first)
		if ( *first == value)
			return first;

	return 0;
}

int main(void)
{
	const int SIZE = 5;
	int ia[SIZE] = {0};
	int value = 0;
	const int* find_value = NULL;

	for (int ix = 0; ix < SIZE; ++ix)
		ia[ix] = rand() % 255;

	for (int ix = 0; ix < SIZE; ++ix)
		cout << '\t' << ix << '\t' << ia[ix] << endl;

	value = ia[0];
	find_value = my_find(ia, ia+SIZE, value);
	if (find_value != 0)
		cout << "find the value " << *find_value << endl;
	else
		cout << "not find value " << value << endl;

	value = ~ ia[0];
	find_value = my_find(ia, ia+SIZE, value);
	if (find_value != 0)
		cout << "find the value " << *find_value << endl;
	else
		cout << "not find value " << value << endl;

	return 0;
}
