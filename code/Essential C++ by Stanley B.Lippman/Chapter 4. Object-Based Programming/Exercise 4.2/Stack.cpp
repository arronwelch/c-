/* Exercise 4.2 */

/*
Extend the Stack class to support both a find() and a count() operation. find() returns
true of false depending on whether the value is found. count() returns the number of
occurrences of the string. Reimplement the main() of Exercise 4.1 to invoke both functions.
*/

#include "Stack.h"

bool Stack::push(const std::string &elem)
{
	if(full())
		return false;

	_stack.push_back(elem);
	return true;
}

bool Stack::pop(std::string &elem)
{
	if(empty())
		return false;

	elem = _stack.back();
	_stack.pop_back();
	return true;
}

bool Stack::peek(std::string &elem)
{
	if(empty())
		return false;

	elem = _stack.back();
	return true;
}

bool Stack::find(const std::string &elem)
{
	return std::find(_stack.begin(), _stack.end(), elem) != _stack.end();
}

int Stack::count(const std::string &elem)
{
	return std::count(_stack.begin(), _stack.end(), elem);
}
