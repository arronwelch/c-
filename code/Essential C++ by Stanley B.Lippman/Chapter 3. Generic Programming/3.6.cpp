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

// <-------------->
// Function Objects
// <-------------->

// plus<type>, minus<type>, negate<type>,
// multiplies<type>, divides<type>, modulus<type>

// less<type>, less_equal<type>, greater<type>
// greater_equal<type>, equal_to<type>, not_equal_to<type>

// &&, ||, and ! operators:
// logical_and<type>, logical_or<type>, logical_not<type>

#include <functional>

sort(vec.begin(), vec.end(), greater<int>());

binary_search(vec.begin(), vec.end(), elem, greater<int>());

transform(fib.begin(), fib.end(),	// (1) range
			pell.begin(),			// (2) the values to apply
			fib_plus_pell.begin(),	// (3) the result of each transformation
			plus<int>());			// (4) the operation to apply

transform(fib.begin(), fib.end(),	// (1)
			fib.begin(),			// (2)
			fib.begin(),			// (3)
			multiples<int>());		// (4)

// Function Object Adapters
vector<int> filter(const vector<int> &vec,
					int val, less<int> &lt)
{
	vector<int> nvec;
	vctor<int>::const_iterator iter = vec.begin();

	// bind2nd(less<int>,val)
	// binds val to the second value of less<int>
	// less<int> now compares each value against val

	while ((iter =
			find_if(iter, vec.end(),
						bind2nd(lt, val))) != vec.end())
	{
		// each time iter != vec.end(),
		// iter addresses an element less than val
		nvec.push_back(*iter);
		iter++;
	}
	return nvec;
}

template <typename InputIterator, typename OutputIterator,
			typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
		OutputIterator at, const ElemType &val, Comp pred)
{
	while ((first = 
			find_if(first, last,
					bind2nd(pred, val))) != last)
	{
		// just to see what is going on ...
		cout << "found value: " << *first << endl;

		// assign value, then advance both iterators
		*at++ = *first++;
	}
	return at;
}
