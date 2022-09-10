// 3.2.1.cpp : iterator class

// first and last are iterator class objects
while (first != last)
{
	cout << *first << endl;
	++first;
}

for (iter = svec.begin();
		iter != svec.end(); ++iter)
			cout << *iter << ' ';

// one possible iterator syntax
// note: not actually used in the STL
iterator< vector, string > iter;

vector<string> svec;

// the standard library iterator syntax
// iter addresses vector elements of type string
// it is initialized to the first element of svec

vector<string>::iterator iter = svec.begin();

const vector<string> cs_vec;

vector<string>::const_iterator = cs_vec.begin();

cout << "string value of element: " << *iter;

cout << "(" << iter->size() << "):" << *iter << endl;

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
IteratorType find(IteratorType first, IteratorType last,
					const elemType &value)
{
	for (; first != last; ++first)
		if (value == *first)
			return first;

	return last;
}
