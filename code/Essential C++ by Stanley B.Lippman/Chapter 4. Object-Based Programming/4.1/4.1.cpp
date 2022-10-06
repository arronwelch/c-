// 4.1.cpp: How to Implement a Class

#include <iostream>
#include <string>
#include <vector>

#include "Stack.h"

using std::cout;
using std::istream;
using std::cin;

// A class declaration begins with the keyword class
// followed by a user-specified class name.
class Stack;

// ok: these uses require a forward declaration of the class
Stack *pt = 0;
void process(const Stack&);

// // The class definition is necessary before we can define an actual
// // Stack class object or refer to any members of the class.
// // The skeleton of a class definition looks like this:
// class Stack {
// public:
// 	// ... public interface
// private:
// 	// ... private implementation
// };

int main()
{
	cout << "Hello, Stack!\n";
	cout << "Stack address of pt: " << pt << '\n';

}

void fill_stack(Stack &stack, istream &is = cin)
{
	string str;
	while (is >> str && ! stack.full())
		stack.push(str);

	cout << "Read in " << stack.size() << " elements\n";
}

