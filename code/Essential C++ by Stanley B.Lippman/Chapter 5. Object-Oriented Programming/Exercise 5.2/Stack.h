
/*
The reimplementation of the class hierarchy illustrates a concrete class hierarchy; that is, we
replace our pure abstract Stack class with our implementation of LIFO_Stack, renaming it Stack.
Although Stack serves as a base class, it also represents actual objects within our applications.
Thus it is termed a concrete base class. Peekback_Stack is derived from Stack. In this
implementation, it inherits all the members of Stack except peek(), which it overrides. Only the
peek() member function and the destructor of Stack are virtual. The definitions of the member
functions are the same and are not shown.
*/

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <string>
#include <vector>

typedef std::string elemType;

class Stack
{
public:
	Stack(int capacity = 0): _top(0)
	{
		if (capacity)
			_stack.reserve(capacity);
	}
	virtual ~Stack() {};

	bool pop(elemType&);
	bool push(const elemType&);
	bool peek(int, elemType&)
		{ return false; }

	int size() const { return _stack.size(); }
	int top() const { return _top; }

	bool empty() const { return ! _top; }
	bool full() const { return size() >= _stack.max_size(); }
	void print(std::ostream& =std::cout) const;

protected:
	std::vector<elemType> _stack;
	int _top;
};

std::ostream& operator<<(std::ostream &os, const Stack &rhs);

#endif
