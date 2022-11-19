
#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <string>

typedef std::string elemType;

class Stack
{
public:
	virtual ~Stack() {};
	virtual bool pop(elemType&) = 0;
	virtual bool push(const elemType&) = 0;
	virtual bool peek(int index, elemType&) = 0;

	virtual int top() const = 0;
	virtual int size() const = 0;

	virtual bool empty() const = 0;
	virtual bool full() const = 0;
	virtual void print(std::ostream& =std::cout) const = 0;
};

std::ostream& operator<<(std::ostream &os, const Stack &rhs);

void peek(Stack &st, int index);

#endif
