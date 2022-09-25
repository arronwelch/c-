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

int main()
{
	Stack a;
	cout << "a.full() = " << a.full() << '\n';

	return 0;
}
