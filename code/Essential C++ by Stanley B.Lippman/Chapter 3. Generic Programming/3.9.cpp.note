// 3.9.cpp : How to Use Iterator Inserters

while ((first = find_if(first, last, bind2nd(pred, val))) != last)
	*at++ = *first++;

int ia[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
vector<int> ivec(ia,ia+elem_size);

ina ia2[elem_size];
vector<int> ivec2(elem_size);

vector<int> result_vec;
unique_copy(ivec.begin(), ivec.end(),
				back_inserter(result_vec));

vector<string> svec_res;
unique_copy(svec.begin(), svec.end(),
				inserter(svec_res, svec_res.end()));

list<int> ilist_clone;

copy(ilist.begin(), ilist.end(),
		front_inserter(ilist_clone));

int main()
{
	const int elem_size = 8;

	int ia[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
	vector<int> ivec(ia, ia+elem_size);

	// built-in arrays do not support insertion ...
	int ia2[elem_size];
	vector<int> ivec2;

	cout << "filtering integer array for values less than 8\n";
	filter(ia, ia+elem_size, ia2,
			elem_size, less<int>());

	cout << "filtering integer vector for values greater than 8\n";
	filter(ivec.begin(), ivec.end(),
			back_inserter(ivec2),
			elem_size, less<int>());
}
