// 1.2 Defining and Initializing a Data Object

// The name can be any combination of letters, numbers and the underscore.
// Letters are case-sensitive.
// A name cannot begin with a number.
// Also, a name must not match a language keyword exactly.

#include <iostream>
#include <string>
#include <complex>

using namespace std;

int main(void)
{
	string user_name;	// user name
	int usr_val;		// the value entered by the user
	int num_tries = 0;	// the number of guesses a user makes and
	int num_right = 0;	// the number of correct guesses are also integer objects.

	// The use of the assignment operator(=) for initialization is inherited 
	// from the C language.
	string sequence_name = "Fibonacci";

	// It does not work well with class objects that require multiple initial values
	complex<double> purei(0, 7);

	double usr_score = 0.0;	// the user's running score

	// The char keyword represents a character type.
	// A character marked by a pair of single quotations represents a character literal
	// 'a', '7', ';', and so on.

	// Some special built-in character literals are the following
	// (they are sometimes called escape sequences):
	// '\n'		newline
	// '\t'		tab
	// '\0'		null
	// '\''		single quote
	// '\"'		double quota
	// '\\'		backslash

	char usr_more;		// the user's response in a character data object
	cout << "Try another sequence? Y/N? ";
	cin >> usr_more;

	user_name = "Anna";
	cout << '\n' << '\t' << user_name << endl;
	"F:\\essential\\programs\\chapter1\\ch1_main.cpp";
	bool go_for_it = true;

	const int max_tries = 3;
	const double pi = 3.14159;

	// max_tries = 42;	// error: const object
}
