// 2.3 Providing Default Parameter Values

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// header file declaration specifies default value
// let's call the header file: NumericSeq.h

void display(const vector<int> &vec, ostream &os = cout);

// program text file definition includes header file
// the definition itself does not specify the default value

// #include "NumericSeq.h"

void display(const vector<int> &vec, ostream &os)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}

void swap(int &val1, int &val2, ofstream *ofil = 0)
{
	if (ofil != 0)
	(*ofil) << "swap(" << val1
		 << ", " << val2 << ")\n";

	int tmp = val1;
	val1 = val2;
	val2 = tmp;

	if (ofil != 0)
	(*ofil) << "after swap(): val1 = " << val1
		 << " val2 = " << val2 << endl;
}

void bubble_sort(vector<int> &vec, ofstream *ofil = 0)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		for (int jx = ix+1; jx < vec.size(); ++jx)
			if (vec[ix] > vec[jx])
			{
				if (ofil != 0)
					(*ofil) << "about to call swap! ix: " << ix
						 << " jx: " << jx << "\tswapping: "
						 << vec[ix] << "  with " << vec[jx] << endl;

				swap(vec[ix], vec[jx], ofil);
			}
}

int main(void)
{
	int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> vec(ia, ia+8);

	cout << "vector before sort: ";
	display(vec);

	// no debug information --
	// it is as if we invoked bubble_sort(vec, 0);
	bubble_sort(vec);
	cout << "vector after sort:(no debug information) ";
	display(vec);

	vector<int> vec1(ia, ia+8);
	cout << "vector1 before sort: ";
	display(vec1);
	// ok: debug information generated ...
	ofstream ofil("data.txt");
	bubble_sort(vec1, &ofil);
	display(vec1,ofil);

	return 0;
}
