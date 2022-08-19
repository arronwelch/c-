// 3.2 Making Sense of Iterators

// first and last are iterator class objects
while (first != last)
{
	cout << *first << ' ';
	++first;
}

for (iter = svec.begin();
		iter != svec.end(); ++iter)
			cout << *iter << ' ';

// one possible iterator syntax
// note: not actually used in the STL
iterator< vector, string > iter; // invalid code

// the standard library iterator syntax
// iter addresses vector elements of type string
// it is initialied to the first element of svec

vector<string>::iterator iter = svec.begin();

vector<string>::const_iterator cs_iter = cs_vec.begin();

// A const_iterator allows us to read the vector elements but not write to them.
cout << "string value of element: " << *iter;

cout << "(" << cs_iter->size() << "): " << *iter << endl;

template <typename elemType>
void display(const vector<elemType> &vec, ostream &os)
{
	vector<elemType>::const_iterator iter = vec.begin();
	vector<elemType>::const_iterator end_it = vec.end();

	// if vec is empty, iter and end_it are equal
	// and the for-loop never executes
	for (; iter != end_it; ++iter)
		os << *iter << ' ';
	os << endl;
}

template <typename IteratorType, typename elemType>
IteratorType
find(IteratorType first, IteratorType last,
		const elemType &value)
{
	for (; first != last; ++first)
		if (value == *first)
			return first;

	return last;
}

const int asize = 8;
int ia[asize] = { 1, 1, 2, 3, 5, 8, 13, 21 };

// initialize the list and vector with the 8 element of ia
vector<int> ivec(ia, ia+asize);
list<int> ilist(ia, ia+asize);

int *pia = find(ia, ia+asize, 1024);
if (pia != ia+asize)
	// found ...

vector<int>::iterator it;
it = find(ivec.begin(), ivec.end(), 1024);
if (it != ivec.end())
	// found ...

list<int>::iterator iter;
iter = find(ilist.begin(), ilist.end(), 1024);
if (iter != ilist.end())
	// found ...

// 1. Search_algorithms:
// find(), count(), adjacent_find(), find_if(), count_if(),
// binary_search(), find_first_of().

// 2. Sorting and general ordering algorithms:
// merge(), partial_sort(), partition(), random_shuffle(), reverse(), rotate(), sort().

// 3. Copy, deletion, and substitution algorithms:
// copy(), remove(), remove_if(), replace(), replace_if(), swap(), unique().

// 4. Relational algorithms:
// equal(), includes(), mismatch().

// 5. Generation and mutation algorithms:
// fill(), for_each(), generate(), transform().

// 6. Numeric algorithms:
// accumulate(), adjacent_difference(), partial_sum(), inner_product().

// 7. Set algorithms:
// set_union(), set_difference().

// The algorithms ending with the _if suffix take either a pointer to function or a function
// object to determine equality.
