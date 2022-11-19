
#include "Peekback_Stack.h"
#include <iterator>

bool Peekback_Stack::pop(elemType &elem) {
	if (empty()) return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool Peekback_Stack::push(const elemType &elem) {
	if (full()) return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

void Peekback_Stack::print(std::ostream &os) const {
	std::vector<elemType>::const_reverse_iterator
		rit = _stack.rbegin(),
		rend = _stack.rend();

	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << std::endl;
}

bool Peekback_Stack::
peek(int index, elemType &elem)
{
	if (empty())
		return false;

	if (index < 0 || index >= size())
		return false;

	elem = _stack[index];
	return true;
}
