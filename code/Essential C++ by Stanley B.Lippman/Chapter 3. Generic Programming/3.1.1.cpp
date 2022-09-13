// 3.1.1.cpp

#include <cstdlib>		// rand()
#include <iostream>		// std::cout
#include <vector>		// std::vector

const int* my_find(const std::vector<int> &vec, int &value)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] == value)
			return &vec[ix];

	return 0;
}

int main(void)
{
	const int ASIZE = 10;
	std::vector<int> ivec;
	int value = 0;
	const int* find_value = NULL;

	// random initial vector:
	for (int ix = 0; ix < ASIZE; ++ix) {
		ivec.push_back(std::rand() % 255);
	}

	// print all elements of vector ivec:
	for (int ix = 0; ix < ASIZE; ++ix)
		std::cout << ivec[ix] << ' ';
	std::cout << '\n';

	value = ivec[3];
	find_value = my_find(ivec, value);
	if (find_value != 0)
		std::cout << "find the value " << *find_value << '\n';
	else
		std::cout << "not find value " << value << '\n';

	value = ~ivec[3];
	find_value = my_find(ivec, value);
	if (find_value != 0)
		std::cout << "find the value " << *find_value << '\n';
	else
		std::cout << "not find value " << value << '\n';

	return 0;
}
