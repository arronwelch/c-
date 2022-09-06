// 3.1.4.2.cpp

#include <iostream>
#include <cstdio>
using namespace std;

template <typename elemType>
const elemType* my_find(const elemType *array, const int size,
						const elemType &value)
{
	if (! array || size < 1)
		return 0;

	// ++array increments array by one element
	for (int ix = 0; ix < size; ++ix, ++array)
		// *array dereferences the address
		if ( *array == value)
			return array;

	return 0; // value not found
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
	find_value = my_find(ia, SIZE, value);
	if (find_value != 0)
		cout << "find the value " << *find_value << endl;
	else
		cout << "not find value " << value << endl;

	value = ~ ia[0];
	find_value = my_find(ia, SIZE, value);
	if (find_value != 0)
		cout << "find the value " << *find_value << endl;
	else
		cout << "not find value " << value << endl;

	// array[2]
	cout << "ia[2] = " << ia[2] << endl;
	// *(array+2)
	cout << "*(ia+2) = " << *(ia+2) << endl;

	// the address of array
	cout << "the address of ia: \t" << ia << endl;
	// the address of array+2
	cout << "the address of ia+2: \t" << ia+2 << endl;

	return 0;
}
