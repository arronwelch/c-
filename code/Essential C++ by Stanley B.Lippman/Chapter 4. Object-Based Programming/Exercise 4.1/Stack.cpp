/* Exercise 4.1 */

/*
Create a Stack.h and a Stack.suffix, where suffix is whatever convention your compiler
or project follows. Write a main() function to exercise the full public interface, and compile
and execute it. Both the program text file and main() must include Stack.h:

#include "Stack.h"

*/

#include "Stack.h"

bool push(const std::string &elem)
{
	if(full())
		return false;

	_stack.push_back(elem);
	return true;
}

bool pop(std::string &elem)
{
	if(empty())
		return false;

	elem = _stack.back();
	_stack.pop_back();
	return true;
}

bool peek(std::string &elem)
{
	if(empty())
		return false;

	elem = _stack.back();
	return true;
}

