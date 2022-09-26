/* Exercise 4.2 */

/*
Extend the Stack class to support both a find() and a count() operation. find() returns
true of false depending on whether the value is found. count() returns the number of
occurrences of the string. Reimplement the main() of Exercise 4.1 to invoke both functions.
*/

#include <iostream>
#include "Stack.h"

using std::string;
using std::cout;
using std::cin;
using std::cerr;

int main()
{
	Stack testStack;
	string word;
	cout << "Please enter some strings: ";
	while (cin >> word && !testStack.full())
		testStack.push(word);
	if(testStack.empty())
		cerr << "Sorry, the stack is empty.\n";
	if(testStack.peek(word))
		cout << "There are " << testStack.size() << " strings in the stack.\n";
	//cin.clear();
	cout << "Please enter the word you want to query: ";
	cin >> word;
	bool testFind = testStack.find(word);
	int testCount = testFind ? testStack.count(word) : 0;
	if (testFind)
		cout << "The word " << word << " is in the stack, and it occurs " << testCount << " times.\n";
	else
		cout << "The word " << word << " is not in the stack.\n";

	cout << "\nThe reverse order: ";
	while (testStack.size())
		if (testStack.pop(word))
			cout << word << ' ';
	cout << "\nThere are " << testStack.size() << " strings in the stack.\n";

	return 0;
}
