
#include "Stack.h"

std::ostream& operator<<(std::ostream &os, const Stack &rhs)
	{ rhs.print(); return os; }

void peek(Stack &st, int index)
{
	std::cout << std::endl;
	std::string t;
	if (st.peek(index, t))
		std::cout << "peek: " << t;
	else std::cout << "peek failed!";
	std::cout << std::endl;
}

