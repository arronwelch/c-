// 3.1.3.cpp

#include <iostream>		// std::cout
#include <cstdlib>		// std::rand()

#define FIXED_SIZE 24
#define SIZE 44

int min_fixed_size(int array[FIXED_SIZE])
{
	int min = array[0];
	for (int ix =0; ix < FIXED_SIZE; ++ix)
		if (array[ix] < min)
			min = array[ix];

	std::cout << "\"enter fixed size array!\"" << '\n';
	return min;
}

int min_unfixed_size(int *array, const int size)
{
	int min = array[0];
	for (int ix =0; ix < size; ++ix)
		if (array[ix] < min)
			min = array[ix];

	std::cout << "\"array size is " << size << "\"\n";
	return min;
}

int main(void)
{
	int array[SIZE];

	for (int ix = 0; ix < SIZE; ++ix)
		array[ix] = std::rand() % 255;

	for (int ix = 0; ix < SIZE; ++ix)
		std::cout << "\t" << ix << ":\t" << array[ix] << '\n';
	std::cout << '\n';

	std::cout << "the array size is " << FIXED_SIZE << "\t the min = " << min_fixed_size(array) << '\n';
	std::cout << "the array size is " << SIZE << "\t the min = " << min_unfixed_size(array, SIZE) << '\n';

	return 0;
}
