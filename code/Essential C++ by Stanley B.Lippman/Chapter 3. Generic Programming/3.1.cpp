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



