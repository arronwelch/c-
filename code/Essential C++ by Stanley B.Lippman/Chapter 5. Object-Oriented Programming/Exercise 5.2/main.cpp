/* Exercise 5.1: main.cpp */

/*
5.2	Reimplement the class hierarchy of Exercise 5.1 so that the base Stack class implements the
shared, type-independent members.

The reimplementation of the class hierarchy illustrates a concrete class hierarchy; that is, we
replace our pure abstract Stack class with our implementation of LIFO_Stack, renaming it Stack.
Although Stack serves as a base class, it also represents actual objects within our applications.
Thus it is termed a concrete base class. Peekback_Stack is derived from Stack. In this
implementation, it inherits all the members of Stack except peek(), which it overrides. Only the
peek() member function and the destructor of Stack are virtual. The definition of the member
functions are the same and are not shown.
*/

#include <iostream>
#include "Peekback_Stack.h"

int main()
{
	std::cout << "Hello, Exercise 5.2!\n";
	Stack st;
	std::string str;
	while (std::cin >> str && ! st.full())
		st.push(str);

	std::cout << '\n' << "About to call peek() with Stack" << std::endl;
	std::cout << std::endl;
	if (st.peek(st.top()-1, str))
		std::cout << "peek: " << str;
	else std::cout << "peek failed!";
	std::cout << std::endl;
	std::cout << st;

	Peekback_Stack pst;

	while (! st.empty()) {
		std::string t;
		if (st.pop(t))
			pst.push(t);
	}

	std::cout << "About to call peek() with Peekback_Stack" << std::endl;
	std::cout << std::endl;
	if (pst.peek(pst.top()-1, str))
		std::cout << "peek: " << str;
	else std::cout << "peek failed!";
	std::cout << std::endl;
	std::cout << pst;
}

/*
$ make all
$ ./a.out
$ once upon a time
$ <Ctrl+Shift+d>
$ make clean
*/
