// 3.1.3.cpp

#include <iostream>
#include <cstdio>
#define SIZE_ONE 24
#define SIZE_TWO 44

using namespace std;

int min_one(int array[SIZE_ONE])
{
	int min = array[0];
	for (int ix =0; ix < SIZE_ONE; ++ix)
		if (array[ix] < min)
			min = array[ix];

	cout << "fixed size array!" << endl;
	return min;
}

int min_two(int *array)
{
	int min = array[0];
	for (int ix =0; ix < SIZE_TWO; ++ix)
		if (array[ix] < min)
			min = array[ix];

	cout << "array size is None!" << endl;
	return min;
}

int main(void)
{
	int array[SIZE_TWO];

	for (int ix = 0; ix < SIZE_TWO; ++ix)
		array[ix] = rand() % 255;

	for (int ix = 0; ix < SIZE_TWO; ++ix)
		cout << "\t" << ix << ":\t" << array[ix] << endl;
	cout << endl;

	cout << "test size array min:" << min_one(array) << endl;
	cout << "test NoneSize array min:" << min_two(array) << endl;

	return 0;
}
