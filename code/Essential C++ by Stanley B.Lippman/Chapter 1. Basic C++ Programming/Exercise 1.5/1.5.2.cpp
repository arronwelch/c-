/* Exercise 1.5 : 1.5.2.cpp */

/*
	Write a program to ask the user his or her name. Read the response.
	Confirm that the input is at least two characters in length.If the name
	seems valid, respond to the user. Provide two implementations: one using
	a C-style character string, and the other using a string class oject.
*/

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string name;

	cout << "Please enter your name:(at least 2 characters)\n";
	cin >> name;

	if (name.size() < 2)
		cout << "user name at least 2 characters!\n";
	else
		cout << "Hello! " << name << endl;

	return 0;
}
