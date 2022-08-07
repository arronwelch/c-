/* Exercise 1.5 : e.1.5.2.cpp (C-style) */

/*
 * Write a program to ask the user his or her name. Read the response.
 * Confirm that the input is at least two characters in length.If the name
 * seems valid, respond to the user. Provide two implementations: one using
 * a C-style character string, and the other using a string class oject.
 */

#include <iostream>
#include <iomanip>	// setw()
#include <cstring>	// strlen()
using namespace std;

int main(void)
{
	// must allocate a fixed size
	const int nm_size = 128;
	char user_name[nm_size];

	cout << "Please enter your name: ";
	cin >> setw(nm_size) >> user_name;

	switch(strlen(user_name)) {
		case 0:
		{
			cout << "Ah, the user with no name. "
				 << "Well, ok, hi, user with no name!\n";
			break;
		}
		case 1:
		{
			cout << "A 1-character name? Hmm, have you read Kafka?: "
				 << "hello, " << user_name << endl;
			break;
		}
		case 127:
		{
			// maybe string was truncated by setw()
			cout << "That is a very big name, indeed -- "
				 << "we may have needed to shorten it!\n"
				 << "In any case,\n";
			// no break -- we fall through ...
		}
		default:
		{
			// the 127 case drops through to here -- no break
			// any string longer than 1 character
			cout << "Hello, " << user_name
				 << " -- happy to make your acquaintance!\n";
			break;
		}
	}

	return 0;
}
