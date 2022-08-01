// 2.5 Declaring a Function Inline

#include <iostream>
#include <vector>

using namespace std;

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

// calculate up to size elements of Fibonacci sequence
// return address of static container holding elements
const vector<int>*
fibon_seq(int size)
{
	static vector<int> elems;
	if(! is_size_ok(size))
		return 0;

	for (int ix = elems.size(); ix <size; ++ix)
		if (ix == 0 || ix == 1)
			elems.push_back(1);
		else elems.push_back(elems[ix-1]+elems[ix-2]);

	return &elems;
}

void display(const vector<int> &, ostream & = cout);

void display(const vector<int> &vec, ostream &os)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}

// returns the Fibonacci element at position pos
// (we must adjust by 1 because first is stored at 0)
// returns false if position is unsupported
// ok: now fibon_elem() is an inline function
inline bool fibon_elem(int pos, int &elem)
{
	const vector<int> *pseq = fibon_seq(pos);

	if (! pseq)
	{
		elem = 0;
		return false;
	}

	elem = (*pseq)[pos-1];
	return true;
}

int main(void)
{
	int pos = 8;
	int elem = 0;

	display(*fibon_seq(8));
	if (fibon_elem(8, elem))
		cout << "fibon_elem(8) = " << elem << endl;

	return 0;
}
