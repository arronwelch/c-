// What Is The this Pointer?

#include <iostream>

using std::cout;

class Triangular{
public:
	Triangular()
		: _length(1), _beg_pos(1), _next(0)
	{}
	Triangular& copy(const Triangular &rhs);

private:
	mutable int _next;
	int _length;
	int _beg_pos;
};

Triangular& Triangular::
copy(const Triangular &rhs)
{
	// check that the two objects are not the same
	if (this != &rhs)
	{
		_length = rhs._length;
		_beg_pos = rhs._beg_pos;
		_next = rhs._beg_pos - 1;
	}

	return *this;
}

int main()
{
	cout << "Hello, this Pointer?\n";
}
