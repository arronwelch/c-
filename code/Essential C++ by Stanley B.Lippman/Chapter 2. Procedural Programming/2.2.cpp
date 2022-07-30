// 2.2 Invoking a Function

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void display(const vector<int> &vec)
{
	for(int ix = 0; ix < vec.size(); ++ix)
		cout << vec[ix] << ' ';
	cout << endl;
}

void display(const vector<int> *vec)
{
	if (! vec)
	{
		cout << "display(): the vector pointer is 0\n";
		return;
	}
	for(int ix = 0; ix < vec->size(); ++ix)
		cout << (*vec)[ix] << ' ';
	cout << endl;
}

/*
 * OK: by declaring val1 and val2 as references
 *     changes to the two parameters within swap()
 *     are reflected in the objects passed to swap()
 */

// ofstream ofil("text_out1");
void swap(int & val1, int & val2)
{
	// cout << "swap(" << val1
	// 	 << ", " << val2 << ")\n";

	// what is the relationship between
	// the formal parameters val1, val2

	// and the actual arguments vec[ix] and vec[jx]?

	/*
	 * note that our code within swap()
	 * does not change -- only the relationship
	 * between the parameters of swap() and the
	 * objects passed to swap() changes
	 */
	int temp = val1;
	val1 = val2;
	val2 = temp;
	// cout << "after swap(): val1 " << val1
	// 	 << " val2:" << val2 << "\n";
}

// void swap(int &val1, int &val2)
// {
// 	int temp = val1;
// 	val1 = val2;
// 	val2 = temp;
// }

// ofstream ofil("text_out1");
void bubble_sort(vector<int> &vec)
{
	for(int ix = 0; ix < vec.size(); ++ix)
		for (int jx = ix + 1; jx < vec.size(); ++jx)
			if(vec[ix] > vec[jx]) {
				// cout << "about to call swap!"
				// 	 << " ix: " << ix << " jx: " << jx << '\t'
				// 	 << " swapping: " << vec[ix]
				// 	 << " with " << vec[jx] << endl;
				// display(vec);

					// ok: actual swap code ...
				swap(vec[ix], vec[jx]);
			}
}

vector<int> fibon_seq(int size)
{
	if (size <= 0 || size > 1024)
	{
		cerr << "Warning: fibon_seq(): "
			 << size << " not supported -- resetting to 8\n";
		size = 8;
	}

	vector<int> elems(size);
	for (int ix = 0; ix < size; ++ix)
		if (ix == 0 || ix == 1)
			elems[ix] = 1;
		else elems[ix] = elems[ix - 1] + elems[ix - 2];

	return elems;
}

extern int a; // declaration to the end of the file

int main(void)
{
	int ia[8] = { 8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> vec(ia, ia+8);

	cout << "vector before sort: ";
	display(&vec);	// pass the address now

	bubble_sort(vec);

	cout << "vector after sort: ";
	display(vec);	// pass by value or by reference?

	int ival = 1024;	// an object of type int
	int *pi = &ival;	// a pointer to an object of type int
	int &rval = ival;	// a reference to an object of type int

	cout << "before : rval = " << rval << endl;
	cout << "before : ival = " << ival << endl;

	int jval = 4096;
	rval = jval;		// repair book error!!!
	// we assign ival, the object rval refers to, the value stored by jval.
	// We do not cause rval to now refer to jval.
	// A reference cannot be reassigned to refer to another object.

	cout << "after : rval = " << rval << endl;
	cout << "after : ival = " << ival << endl;

	ival = 2048;
	pi = &rval;
	// we assign pi the address of ival, the object rval refers to.
	cout << "*pi = " << *pi << endl;

	// returning elems by value is OK: The copy of the object returned exists 
	// outside the function.
	display(fibon_seq(-1));

	cout << "a is a outside, has file scope: a = " << a << endl;

	// int *pi;
	// pi = new int;
	pi = new int(1024);
	cout << "*pi = " << *pi << endl;
	delete pi;

	int *pia = new int[24];
	delete [] pia;

	return 0;
}

int a = 1;
