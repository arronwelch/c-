
#include "Stack.h"
#include <iterator>

bool Stack::pop(elemType &elem) {
	if (empty()) return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool Stack::push(const elemType &elem) {
	if (full()) return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

void Stack::print(std::ostream &os) const {
	std::vector<elemType>::const_reverse_iterator
		rit = _stack.rbegin(),
		rend = _stack.rend();

	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Stack &rhs)
	{ rhs.print(); return os; }
