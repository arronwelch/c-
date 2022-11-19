#ifndef _LIFO_STACK_H
#define _LIFO_STACK_H

#include "Stack.h"
#include <vector>

class LIFO_Stack : public Stack {
public:
	LIFO_Stack(int capacity = 0) : _top(0)
		{ if (capacity) _stack.reserve(capacity); }
	int size() const { return _stack.size(); }
	bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }
	int top() const { return _top; }
	void print(std::ostream &os=std::cout) const;

	bool pop(elemType &elem);
	bool push(const elemType &elem);
	bool peek(int, elemType&) { return false; }
private:
	std::vector<elemType> _stack;
	int _top;
};

#endif
