// 2.4 Using Local Static Objects

#include <iostream>
#include <vector>

using namespace std;

const vector<int>*
fibon_seq(int size)
{
	const int max_size = 1024;
	static vector<int> elems;
	// do the logic to populate it ...
	if (size <= 0 || size > max_size) {
		cerr << "fibon_seq(): oops: invalid size: "
			 << size << " -- can't fulfill request.\n";
		return 0;
	}

	// if size is equal to or greater than elems.size(),
	// no calculations are necessary ...
	for (int ix = elems.size(); ix < size; ++ix) {
		if (ix == 0 || ix == 1)
			elems.push_back(1);
		else elems.push_back(elems[ix-1]+elems[ix-2]);
	}

	return &elems;
}

int main(void)
{
	int size = 0;
	const vector<int> *seq;

	cout << "Please enter the size of Fibonacci Sequence:" << endl;
	cin >> size;

	cout << "The first " << size << " elements of Fibonacci Sequence:" << endl;
	seq = fibon_seq(size);
	for (int ix = 0; ix < size; ++ix)
		cout << (*seq)[ix] << ' ';
	cout << endl;

	return 0;
}
