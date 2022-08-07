/* Exercise 2.1: e.2.1.cpp */

/*
main() [in Section 2.1] allows the user to enter only one position value and then terminates.
If a user wishes to ask for two or more positions,he must execute the program two or more 
times. Modify main() [in Section 2.1] to allow the user to keep entering positions until he
indicates he wished to stop.
*/

#include <iostream>
using namespace std;

bool fibon_elem(int, int&);

int main()
{
	int pos, elem;
	char ch;
	bool more = true;

	while (more)
	{
		cout << "Please enter a position: ";
		cin >> pos;

		if (fibon_elem(pos, elem))
			cout << "element # " << pos
				 << " is " << elem << endl;
		else
			cout << "Sorry. Could not calculate element # "
				 << pos << endl;

		cout << "would you like to try again? (y/n) ";
		cin >> ch;
		// if ( ch != 'y' && ch != 'Y')
		if ( ch == 'n' || ch == 'N')
			more = false;
	}
	cout << "Bye!\n";

	return 0;
}

bool fibon_elem(int pos, int &elem)
{
	// check if invalid position ...
	if (pos <= 0 || pos > 1024)
	{
		cerr << "Oops! invalid positon!" << endl;
		elem = 0;
		return false;
	}

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
