/* Exercise 4.1 */

/*
Create a Stack.h and a Stack.suffix, where suffix is whatever convention your compiler
or project follows. Write a main() function to exercise the full public interface, and compile
and execute it. Both the program text file and main() must include Stack.h:

#include "Stack.h"

*/

#include <iostream>
#include "Stack.h"

using std::cout;
using std::string;

int main()
{
	Stack a;
	string elem = "TestString1";
	cout << "push the first elem string: " << elem << ". return " << a.push(elem) << '\n';

	elem = "TestString2";
	cout << "push the second elem string: " << elem << ". return " << a.push(elem) << '\n';

	elem = "TestString3";
	bool pop_result = a.pop(elem);
	cout << "pop the string to elem : " << elem << ". return " << pop_result << '\n';

	cout << "a.empty() = " << a.empty() << '\n';
	cout << "a.full() = " << a.full() << '\n';
	cout << "a.size() = " << a.size() << '\n';

	return 0;
}
