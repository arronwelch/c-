#ifndef _PEEKBACK_STACK_H
#define _PEEKBACK_STACK_H

#include "Stack.h"
#include <vector>

class Peekback_Stack : public Stack {
public:
	Peekback_Stack(int capacity = 0)
		: Stack(capacity) {}
	bool peek(int index, elemType& elem);
};

#endif
