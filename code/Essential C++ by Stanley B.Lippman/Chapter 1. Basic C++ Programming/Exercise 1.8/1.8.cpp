/* Exercise 1.8 : 1.8.cpp */

/*
	The switch statement of Section 1.4 displays a different consolation message based on
	the number of wrong guesses.Replace this with an array fo four string messages that can
	be indexed based on the number of wrong guesses.
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int num_err;
	string msg[] = {
	"Oops! Nice guess but not quite it.",
	"Hmm. Sorry. Wrong again.",
	"Ah, this is harder than it looks, isn't it?",
	"It must be gettig pretty frustrating by now!",
	"num error!"
	};

	cout << "Please enter the error number:\n";
	cin >> num_err;

	if(num_err < 0)
		num_err = 4;
	else if(num_err > 3)
		num_err = 4;
	cout << msg[num_err] << endl;

	return 0;
}
