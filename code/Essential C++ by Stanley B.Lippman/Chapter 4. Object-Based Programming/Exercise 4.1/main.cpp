/* Exercise 4.1 */

/*
Create a Stack.h and a Stack.suffix, where suffix is whatever convention your compiler
or project follows. Write a main() function to exercise the full public interface, and compile
and execute it. Both the program text file and main() must include Stack.h:

#include "Stack.h"

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
	cout << "The reverse order: ";
	while (testStack.size())
		if (testStack.pop(word))
			cout << word << ' ';
	cout << "\nThere are " << testStack.size() << " strings in the stack.\n";

	return 0;
}
