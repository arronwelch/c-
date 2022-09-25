/* Exercise 4.1 */

/*
Create a Stack.h and a Stack.suffix, where suffix is whatever convention your compiler
or project follows. Write a main() function to exercise the full public interface, and compile
and execute it. Both the program text file and main() must include Stack.h:

#include "Stack.h"

*/

#ifndef _Stack_h_
#define _Stack_h_

#include <string>
#include <vector>
//using std::string;
//using std::vector;

class Stack;

class Stack{
public:
	bool push(const std::string &elem);
	bool pop(std::string &elem);
	bool peek(std::string &elem);

	bool empty();
	bool full();

	int size() { return _stack.size(); }
private:
	std::vector<std::string> _stack;
};

inline bool
Stack::empty()
	{ return _stack.empty(); }

inline bool
Stack::full()
	{ return _stack.size() == _stack.max_size(); }

#endif
