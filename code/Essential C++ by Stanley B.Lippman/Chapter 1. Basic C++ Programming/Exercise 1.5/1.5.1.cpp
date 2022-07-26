/* Exercise 1.5 : 1.5.1.cpp */

/*
	Write a program to ask the user his or her name. Read the response.
	Confirm that the input is at least two characters in length.If the name
	seems valid, respond to the user. Provide two implementations: one using
	a C-style character string, and the other using a string class oject.
*/

#include <iostream>

using namespace std;

int main(void)
{
	const int str_size = 100;
	char name[str_size];
	int ix = 0;

	cout << "Please enter your name:(at least 2 characters)\n";
	cin >> name;

	for ( ix = 0; ix < str_size && name[ix] != '\0'; ix++)
		;
	if (ix < 2)
		cout << "user name at least 2 characters!\n";
	else
		cout << "Hello! " << name << endl;

	return 0;
}
