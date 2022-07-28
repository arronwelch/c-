// Exercise 2.1 : e.2.1.cpp

/*
 *	main(), presented earlier, allows the user to enter only one position value and then terminates. If
	a user wished to ask for two or more positions, she must execute the program two or more times.
	Modify main() to allow the user to keep entering positions until she indicates she wishes to stop.
 */

#include <iostream>
using namespace std;

bool fibon_elem(int, int&);

int main(void)
{
	char ch;
	bool go_on = true;
	int pos;
	int elem;

	while(go_on == true)
	{
		cout << "Please enter a position: ";
		cin >> pos;

		if(fibon_elem(pos, elem))
			cout << "element # " << pos
				 << " is " << elem << endl;
		else
			cout << "Sorry. Could you not calculate element # "
				 << pos << endl;
		
		cout << "Continue?(Y/N)";
		cin >> ch;
		if(ch == 'N' || ch == 'n')
			go_on = false;
	}
	cout << "Bye!\n";

	return 0;
}

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
