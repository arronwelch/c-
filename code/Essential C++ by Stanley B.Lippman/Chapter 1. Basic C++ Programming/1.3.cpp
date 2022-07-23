// 1.3 Writting Expressions

// Arithmetic Operators
// +	addition		a + b
// -	subtraction		a - b
// *	multiplication	a * b
// /	division		a / b
// %	remainder		a % b

// The division of two integer values yields a while number.Any remainder is truncated;there
// is no rounding.The remainder is accessed using the % operator:

// 5 / 3 evaluates to 1 while 5 % 3 evaluates to 2
// 5 / 4 evaluates to 1 while 5 % 4 evaluates to 1
// 5 / 5 evaluates to 1 while 5 % 5 evaluates to 0

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	// string a_string = "these statement are executed many times, with"
	// " a_string representing a different value each time"
	// " and cnt growing by one with each execution ...\n";

	const int line_size = 8;
	int cnt = 1;
	vector<string> a_string = {
		"these","statement", "are", "executed", "many", "times,", "with",
		"a_string", "representing", "a", "different", "value", "each", "time",
		"and", "cnt", "growing", "by", "one", "with", "each", "execution", "...",
	};

	// these statement are executed many times, with
	// a_string representing a different value each time
	// and cnt growing by one with each execution ...
	while (cnt-1 < a_string.size())
	{
		cout << a_string[cnt-1]
			 << (cnt % line_size ? ' ' : '\n');
		cnt++;
	}
	cout << '\n';

	// A compound assignment operator is associated with each arithmetic operator:
	// +=, -=, *=, /=, and %=.
	cnt = cnt + 2;
	cnt += 2;	// add 2 to the current value of cnt
	cnt++;	// add 1 to the current value of cnt
	cnt--;	// subtract 1 from the current value of cnt

	int tries = 0;
	cout << "Are you ready for try #"
		 << ++tries << "?\n";

	/* int */tries = 1;
	cout << "Are you ready for try #"
		 << tries++ << "?\n";

	// Each of the relational operators evaluates to either true or false.
/*
	==	equality				a == b
	!=	inequality				a != b
	<	less than				a <  b
	>	greater than			a >  b
	<=	less than or equal		a <= b
	>=	greater than or equal	a >= b
*/
	bool usr_more = true;
	char usr_rsp;

	cout << "Want to try another sequence? (Y/N)\n");
	cin >> usr_rsp;
	// ask the user if she wishes to continue
	// read the response into usr_rsp
	if (usr_rsp == 'N')
		usr_more = false;

	if (usr_rsp != 'Y')
		usr_more = false;
	else
	if (usr_rsp == 'n')
		usr_more = false;

	// oops this assigns usr_rsp the literal character 'N'
	// and therefore always evaluates as true
	if (usr_rsp = 'N')
		// ...

	// The logical OR operator(||) provides an alternative way of testing the truth condition of
	// multiple expressions:
	if (usr_rsp == 'N' || usr_rsp == 'n')
		usr_more = false;

	// The logical AND operator(&&) evaluates as true only if both its expressions evaluate as
	// true.For example,
	if (password &&
		validate(password) &&
		(acct = retrieve_acct_info(password)))
			// process account ...

	// The logical NOT operator(!) evaluates as true if the expression it is applied to is false
	// For example, rather than write
	if (usr_more == false)
		cout << "Your score for this session is "
			 << usr_score << "Bye!\n";

	if (! usr_more)
		// ...

	// Operator Precedence
	//	logical NOT
	//	arithmetic (*, /, %)
	//	arithmetic (+, -)
	//	relational (<, >, <=, >=)
	//	relational (==, !=)
	//	logical AND
	//	logical OR
	//	assignment

	// Unfortunately, the result of our expression is quite different.
	// Our expression always evaluates to false except when ival is 0!
	! ival % 2 // not quite right
	! (ival % 2) // ok
}
