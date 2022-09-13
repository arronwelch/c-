// 3.1.4.1.cpp

#include <iostream>		// std::cout
#include <cstdlib>		// std::rand()

template <typename elemType>
const elemType* my_find(const elemType *array, const int size,
						const elemType &value)
{
	if (! array || size < 1)
		return 0;

	for (int ix = 0; ix < size; ++ix)
		// we can apply subscript operator to pointer
		if (array[ix] == value)
			return &array[ix];

	return 0; // value not found
}

int main(void)
{
	const int SIZE = 5;
	int ia[SIZE] = {0};
	int value = 0;
	const int* find_value = NULL;

	for (int ix = 0; ix < SIZE; ++ix)
		ia[ix] = std::rand() % 255;

	for (int ix = 0; ix < SIZE; ++ix)
		std::cout << '\t' << ix << '\t' << ia[ix] << '\n';

	value = ia[0];
	find_value = my_find(ia, SIZE, value);
	if (find_value != 0)
		std::cout << "find the value " << *find_value << '\n';
	else
		std::cout << "not find value " << value << '\n';

	value = ~ ia[0];
	find_value = my_find(ia, SIZE, value);
	if (find_value != 0)
		std::cout << "find the value " << *find_value << '\n';
	else
		std::cout << "not find value " << value << '\n';

	// array[2]
	std::cout << "ia[2] = " << ia[2] << '\n';
	// *(array+2)
	std::cout << "*(ia+2) = " << *(ia+2) << '\n';

	// the address of array
	std::cout << "the address of ia: \t" << ia << '\n';
	// the address of array+2
	std::cout << "the address of ia+2: \t" << ia+2 << '\n';

	return 0;
}
