// 3.6.cpp : How to Design a Generic Algorithm

vector<int> less_than_10(const vector<int> &vec)
{
	vector<int> nvec;
	for (int ix = 0; ix < vec.size(); ++ix)
		if ( vec[ix] < 10 )
			nvec.push_back(vec[ix]);
	return nvec;
}

vector<int> less_than(const vector<int> &vec, int less_than_val);

vector<int> filter(const vector<int> &vec,
					int filter_value,
					bool (*pred)(int, int));

bool less_than(int v1, int v2)
	{ return v1 < v2 ? true : false; }

bool greater_than(int v1, int v2)
	{ return v1 > v2 ? true " false; }

vector<int> big_vec;
int value;
// ... fill big_vec and value
vector<int> lt_10 = filter(big_vec, value, less_than);

vector<int> filter(vector<int> &vec,
					int filter_value,
					bool (*pred)(int, int))
{
	vector<int> nvec;

	for (int ix = 0; ix < vec.size(); ++ix)
		// invokes the function addressed by pred
		// tests element vec[ix] against filter_value
		if ( pred(vec[ix], filter_value))
			nvec.push_back(vec[ix]);
	return nvec;
}

int count_occurs(const vector<int> &vec, int val)
{
	vector<int>::const_iterator iter = vec.begin();
	int occurs_count = 0;
	while ((iter = find(iter, vec.end(), val)) != vec.end())
	{
		++occurs_count;
		++iter; // address next element
	}
	return ocurs_count;
}

// plus<type>, minus<type>, negate<type>,
// multiplies<type>, divides<type>, modulus<type>

// less<type>, less_equal<type>, greater<type>
// greater_equal<type>, equal_to<type>, not_equal_to<type>

// &&, ||, and ! operators:
// logical_and<type>, logical_or<type>, logical_not<type>

#include <functional>

sort(vec.begin(), vec.end(), greater<int>());

binary_search(vec.begin(), vec.end(), elem, greater<int>());

