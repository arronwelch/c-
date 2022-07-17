// Exercise 1.4 a.cpp

// Try to extend the program:
// (1) Ask the user to enter both a first and last name and
// (2) modify the output to write out both names.


#include <iostream>
#include <string>
using namespace std;	// haven't explained this yet ...
int main()
{
	cout << "Please enter your first name: ";
	string first_name, last_name;
	cin >> first_name;
	cout << "Please enter your first name: ";
	cin >> last_name;

	cout << '\n'
		 << "Hello, "
		 << first_name
		 << " "
		 << last_name
		 << " ... and goodbye!\n";

	return 0;
}
