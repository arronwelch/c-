// 2.1 How to Write a Function

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

// a declaration of our function
// int fibon_elem(int pos);

/* A second form of comment delimiter
 *
 * 1st and 2nd elements of the Fibonacci Sequence
 * are 1; each subsequent element is the sum of
 * the preceding two elements
 *
 * elem: holds value to be returned
 * n_2, n_1: holds preceding values
 * pos: element position position user requested
 */
int fibon_elem(int pos)
{
	//check for invalid position
	if (pos <= 0)
		// ok, now what?
		exit(-1);

	int elem = 1;	// holds return value
	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ++ix)
	{
		elem = n_2 + n_1;
		n_2 = n_1; n_1 = elem;
	}
	
	return elem;
}

unsigned int u_fibon_elem(unsigned int pos)
{
	//check for invalid position
	if (pos <= 0)
		// ok, now what?
		exit(-1);

	unsigned int elem = 1;	// holds return value
	unsigned int n_2 = 1, n_1 = 1;
	for (unsigned int ix = 3; ix <= pos; ++ix)
	{
		elem = n_2 + n_1;
		n_2 = n_1; n_1 = elem;
	}
	
	return elem;
}
// revised function prototype
// bool fibon_elem(int pos, int &elem);

// forward declaration of fibon_elem()
// makes function known to compiler ...
bool fibon_elem(int, int&);

bool fibon_elem(int pos, int &elem)
{
	// check if invalid position ...
	if (pos <= 0 || pos >1024)
		{ elem = 0; return false; }

	// elem is 1 for positions 1 and 2
	elem = 1;

	int n_2 = 1, n_1 = 1;
	for (int ix = 3; ix <= pos; ++ix)
	{
		elem = n_2 + n_1;
		n_2 = n_1; n_1 = elem;
	}

	return true;
}

int main(void)
{
	int seq_size;

	cout << "Please enter the number of element of Fibonacci Sequence:\n";
	cin >> seq_size;

	cout << "The first " << seq_size
		 << " elements of the Fibonacci Sequence:\n";

	for (int ix = 1; ix <=seq_size; ix++)
		cout << ix << ' ' << fibon_elem(ix) << '\n';
	cout << '\n';

	cout << "element # " << 5000 << " is " << fibon_elem(5000) << endl;

	int max_int = numeric_limits<int>::max();
	double min_dbl = numeric_limits<double>::min();

	cout << "max_int = " << max_int << endl;
	cout << "min_dbl = " << min_dbl << endl;
	cout << "element # " << 5000 << " is " << u_fibon_elem(5000) << endl;

	int pos;
	cout << "Please enter a position: ";
	cin >> pos;

	int elem;
	if(fibon_elem(pos, elem))
		cout << "element # " << pos
			 << " is " << elem << endl;
	else
		cout << "Sorry. Could you not calculate element # "
			 << pos << endl;

	return 0;
}
