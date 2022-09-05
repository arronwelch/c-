// 3.1.1.cpp

#include <iostream>
#include <vector>
using namespace std;

const int* my_find(const vector<int> &vec, int &value)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] == value)
			return &vec[ix];

	return 0;
}

int main(void)
{
	int ia[5] = { 42, 35, 12, 73, 19 };
	vector<int> ivec(ia, ia+5);
	int value = 0;
	const int* find_value = NULL;

	for (int ix = 0; ix < 5; ++ix)
		cout << ia[ix] << ' ';
	cout << endl;

	value = 12;
	find_value = my_find(ivec, value);
	if (find_value != 0)
		cout << "find the value " << *find_value << endl;
	else
		cout << "not find value " << value << endl;

	value = 13;
	find_value = my_find(ivec, value);
	if (find_value != 0)
		cout << "find the value " << *find_value << endl;
	else
		cout << "not find value " << value << endl;

	return 0;
}
