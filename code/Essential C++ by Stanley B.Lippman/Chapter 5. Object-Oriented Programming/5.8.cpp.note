// 5.8.cpp: Initialization, Destruction, and Copy

inline Fibonacci::
Fibonacci(int len, int beg_pos)
	: num_sequence(len, beg_pos, &_elems)
{}

num_sequence::
num_sequence(int len = 1, int bp = 1, vector<int> *pe=0)
	: _length(len), _beg_pos(bp), _pelems(pe) {}

Fibonacci::Fibonacci(const Fibonacci &rhs)
	: num_sequence(rhs)
{}

Fibonacci& Fibonacci::
operator=(const Fibonacci &rhs)
{
	if (this != &rhs)
		// explicit invocation of the base class operator
		num_sequence::operator=(rhs);

	return *this;
}
