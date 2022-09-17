// 3.5.cpp

#include <algorithm>
bool is_elem(vector<int> &vec, int elem)
{
	// if the elem passed in is 34, the 9th element of
	// the Fibonacci sequence, but the stored sequence
	// only holds the first 6 elements: 1,1,2,3,5,8
	// our search will not succeed.
	// Before we invoke binary_search()
	// we must check here if we need to grow the sequence

	return binary_search(vec.begin(), vec.end(), elem);
}

// revised is_elem()
#include <algorithm>

// forward declaration
extern bool grow_vec(vector<int>&, int);

bool is_elem(vector<int> &vec, int elem)
{
	int max_value = max_element(vec.begin(), vec.end());
	if (max_value < elem)
		return grow_vec(vec, elem);

	if (max_value == elem)
		return true;

	return binary_search(vec.begin(), vec.end(), elem);
}

int max_value = vec.empty() ? 0 : vec[vec.size()-1];

vector<int> temp(vec.size());
copy(vec.begin(), vec.end(), temp.begin());
sort(temp.begin(), temp.end());
return binary_search(temp.begin(), temp.end(), elem);

