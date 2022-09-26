/* Exercise 4.2 */

/*
Extend the Stack class to support both a find() and a count() operation. find() returns
true of false depending on whether the value is found. count() returns the number of
occurrences of the string. Reimplement the main() of Exercise 4.1 to invoke both functions.
*/

#ifndef _Stack_h_
#define _Stack_h_

#include <string>
#include <vector>
#include <algorithm>
//using std::string;
//using std::vector;

class Stack;

class Stack{
public:
	bool push(const std::string &elem);
	bool pop(std::string &elem);
	bool peek(std::string &elem);

	bool empty();
	bool full();

	int size() { return _stack.size(); }

	bool find(const std::string &elem);
	int count(const std::string &elem);
private:
	std::vector<std::string> _stack;
};

inline bool
Stack::empty()
	{ return _stack.empty(); }

inline bool
Stack::full()
	{ return _stack.size() == _stack.max_size(); }

#endif
