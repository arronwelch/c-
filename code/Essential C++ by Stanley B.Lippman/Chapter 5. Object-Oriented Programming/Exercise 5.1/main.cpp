/* Exercise 5.1: main.cpp */

/*
5.1	Implement a two-level stack hierarchy. The base class is a pure abstract Stack class
	that minimally supports the following interface: pop(), push(), size(), empty(), full(),
	peek(), and print(). The two concrete derived classes are LIFO_Stack and Peekback_Stack.
	The Peekback_Stack allows the user to retrieve the value of any element in the stack
	without modifying the stack itself.
*/

#include <iostream>
#include "LIFO_Stack.h"
#include "Peekback_Stack.h"

int main()
{
	std::cout << "Hello, Exercise 5.1!\n";
	LIFO_Stack st;
	std::string str;
	while (std::cin >> str && ! st.full())
		st.push(str);

	std::cout << '\n' << "About to call peek() with LIFO_Stack" << std::endl;
	peek(st, st.top()-1);
	std::cout << st;

	Peekback_Stack pst;

	while (! st.empty()) {
		std::string t;
		if (st.pop(t))
			pst.push(t);
	}

	std::cout << "About to call peek() with Peekback_Stack" << std::endl;
	peek(pst, pst.top()-1);
	std::cout << pst;
}
