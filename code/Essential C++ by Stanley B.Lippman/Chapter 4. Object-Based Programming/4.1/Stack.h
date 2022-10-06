// 4.1.cpp : Stack.h

#ifndef _STACK_H_
#define _STACK_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Stack {
public:
	// each operation returns true if able to be carried out
	// pop and peek place the string value within elem
	bool push(const string&);
	bool pop(string &elem);
	bool peek(string &elem);

	bool empty();
	bool full();

	// definition of size() is placed within class
	// other members are simply declared ...
	int size() { return _stack.size(); }
private:
	vector<string> _stack;
};

inline bool
Stack::empty()
{
	return _stack.empty();
}

inline bool Stack::full()
	{ return _stack.size() == _stack.max_size(); }

#endif
