/* Exercise 1.5 : e.1.5.1.cpp (string-style) */

/*
 * Write a program to ask the user his or her name. Read the response.
 * Confirm that the input is at least two characters in length.If the name
 * seems valid, respond to the user. Provide two implementations: one using
 * a C-style character string, and the other using a string class oject.
 */

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string user_name;

	cout << "Please enter your name: ";
	cin >> user_name;

	switch(user_name.size()) {
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
		default:
		{
			// any string longer than 1 character
			cout << "Hello, " << user_name
				 << " -- happy to make your acquaintance!\n";
			break;
		}
	}

	return 0;
}
