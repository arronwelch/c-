// 3.1 The Arithmetic of Pointers

int* find(const vector<int> &vec, int value)
{
	for(int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] == value)
			return &vec[ix];
	return 0;
}

template <typename elemType>
elemType* find(const vector<elemType> &vec,
				const elemType &value)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		if (vec[ix] == value)
			return &vec[ix];
	return 0;
}

template <typename elemType>
elemType* find(const elemType *array, int size,
				const elemType &value);

template <typename elemType>
elemType* find(const elemType *first, const elemType *sentinel,
				const elemType &value);

template <typename elemType>
elemType* find(const elemType *array, int size,
				const elemType &value)
{
	if (! array || size < 1)
		return 0;

	for (int ix = 0; ix < size; ++ix)
		// we can apply subscript operator to pointer
		if (array[ix] == value)
			return &array[ix];

	return 0; // value not found

array[2];

// returns the value of the third element of the array(indexing, remenber, begins at 0). The
// following also returns the value of the third element:

*(array + 2);

}

template <typename> elemType>
elemType* find(const elemType *array, int size,
				const elemType &value)
{
	if (! array || size < 1) return 0;

	// ++array increments array by one element
	for (int ix = 0; ix < size; ++ix, ++array)
		// *array dereferences the address
		if (*array == value)
			return array;
	return 0;
}

template <typename elemType>
elemType* find(const elemType *first,
				const elemType *last, const elemType &value)
{
	if (! first || ! last)
		return 0;

	// while first does not equal to last,
	// compare value with element addressed by first
	// if the two are equal, return first
	// otherwise, increment first to address next element

	for(; first != last; ++first)
		if (*first == value)
			return first;

	return first;
}

int			ia[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };
double		da[6] = { 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };
string		sa[4] = { "pooh", "piglet", "eeyore", "tigger" };

int			*pi = find(ia, ia+8, ia[3]);
double		*pd = find(da, da+6, da[3]);
string		*ps = find(sa, sa+4, sa[3]);

vector<string> svec;

find(&svec[0], &svec[svec.size()], search_value);

if (! svec.empty()) // ... ok, call find()
