// 2.8 Pointers to Functions Add Flexibility

#include <iostream>
#include <vector>

using namespace std;

enum ns_type {
	ns_fibon,
	ns_lucas,
	ns_pell,
	ns_triang,
	ns_square,
	ns_pent
};

const vector<int> *fibon_seq(int size);
// const vector<int> *lucas_seq(int size);
// const vector<int> *pell_seq(int size);
// const vector<int> *triang_seq(int size);
// const vector<int> *square_seq(int size);
// const vector<int> *pent_seq(int size);

bool is_size_ok(int size)
{
	const int max_size = 1024;
	if (size <= 0 || size > max_size)
	{
		cerr << "Oops: requested size is not supported: "
			 << size << " -- can't fulfill request.\n";
		return false;
	}

	return true;
}

const vector<int> *fibon_seq(int size)
{
	static vector<int> elems;
	if(! is_size_ok(size))
		return 0;

	for (int ix = elems.size(); ix < size; ++ix)
		if (ix == 0 || ix == 1)
			elems.push_back(1);
		else
			elems.push_back(elems[ix-1]+elems[ix-2]);

	return &elems;
}

bool seq_elem(int pos, int &elem,
			  const vector<int> * (*seq_ptr)(int))
{
	const vector<int> *pseq = (*seq_ptr)(pos);

	if (! pseq)
	{
		elem = 0;
		return false;
	}

	elem = (*pseq)[pos-1];
	return true;
}

// seq_array is an array of pointers to functions
const vector<int>* (*seq_array[])(int) = {
	fibon_seq,
	// lucas_seq,
	// pell_seq,
	// triang_seq,
	// square_seq,
	// pent_seq
};

int main(void)
{
	const int pos = 10;
	int elem = 0;

	for (int ix = 1; ix < pos+1; ++ix)
	{
		seq_elem(ix, elem, seq_array[0]);
		cout << elem << ' ';
	}
	cout << endl;

	seq_elem(pos, elem, seq_array[0]);

	cout << "seq_array[" << 0 << "] = " << seq_elem(pos, elem, seq_array[0]) << endl;
	cout << "elem[" << pos << "] = " << elem << endl;

	return 0;
}

// int seq_index = 0;
// while (next_seq == true)
// {
// 		seq_ptr = seq_array[++seq_index];
// 		// ...
//	}


