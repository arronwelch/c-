
#include "Peekback_Stack.h"

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
