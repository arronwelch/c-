// 3.1.4.cpp

#include <iostream>
#include <cstdio>
using namespace std;

template <typename elemType>
const elemType* my_find(const elemType *array, const int size,
						const elemType &value)
{
	for (int ix = 0; ix < size; ++ix)
		if (array[ix] == value)
			return &array[ix];

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

	return 0;
}
