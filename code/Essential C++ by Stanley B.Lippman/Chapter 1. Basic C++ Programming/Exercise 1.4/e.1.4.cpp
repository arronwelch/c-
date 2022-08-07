// Exercise 1.4: e.1.4.cpp

// Try to extend the program:
// (1) Ask the user to enter both a first and last name and
// (2) modify the output to write out both names.


#include <iostream>
#include <string>
using namespace std;	// haven't explained this yet ...

int main()
{
	string first_name, last_name;

	cout << "Please enter your first name: ";
	cin >> first_name;

	cout << "hi, " << first_name
		 << "Please enter your last name: ";
	cin >> last_name;

	cout << '\n'
		 << "Hello, "
		 << first_name << ' ' << last_name
		 << " ... and goodbye!\n";

	return 0;
}

/* Test in terminal:
 * >> Please enter your first name: stan
 * >> hi, stan Please enter your last name: lippman
 * >> Hello, stan lippman ... and goodbye!
 */
