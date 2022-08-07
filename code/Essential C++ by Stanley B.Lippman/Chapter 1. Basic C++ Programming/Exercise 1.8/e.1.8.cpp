/* Exercise 1.8 : e.1.8.cpp */

/*
	The switch statement of Section 1.4 displays a different consolation message based on
	the number of wrong guesses.Replace this with an array fo four string messages that can
	be indexed based on the number of wrong guesses.
*/

#include <iostream>
#include <string>
using namespace std;

const char* msg_to_usr(int num_tries)
{
	const int rsp_cnt = 5;
	static const char* usr_msgs[rsp_cnt] = {
		"Go on, make a guess. ",
		"Oops! Nice guess but not quite it.",
		"Hmm. Sorry. Wrong again.",
		"Ah, this is harder than it looks, no?",
		"It must be getting pretty frustrating by now!"
	};
	if (num_tries < 0)
		num_tries = 0;
	else
	if (num_tries >= rsp_cnt)
		num_tries = rsp_cnt - 1;

	return usr_msgs[num_tries];
}

int main(void)
{
	int num_tries;

	cout << "Please enter the tries number:\n";
	cin >> num_tries;

	cout << "msg_to_usr:\n";
	cout << msg_to_usr(num_tries) << endl;

	return 0;
}
