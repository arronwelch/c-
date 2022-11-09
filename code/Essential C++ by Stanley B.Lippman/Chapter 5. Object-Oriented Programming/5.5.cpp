// 5.5.cpp: Defining a Derived Class

// the header file contains the base class definition
#include "num_sequence.h"
#include <vector>

class Fibonacci : public num_sequence {
public:
	Fibonacci(int len = 1, int beg_pos = 1)
		: _length(len), _beg_pos(beg_pos) {}
	virtual int elem(int pos) const;
	virtual const char* what_am_i() const { return "Fibonacci"; }
	virtual ostream& print(ostream &os = cout) const;
	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
protected:
	virtual void gen_elems(int pos) const;
	int _length;
	int _beg_pos;
	static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

int Fibonacci::
elem(int pos) const
{
	if (! check_integrity(pos))
		return 0;

	if (pos > _elems.size())
		Fibonacci::gen_elems(pos);

	return _elems[pos-1];
}

ostream& Fibonacci::print(ostream &os) const
{
	return os;
}

void Fibonacci::gen_elems(int pos) const
{
	if (_elems.empty())
		{ _elems.push_back(1); _elems.push_back(1); }

	if (_elems.size() < pos)
		{
			int ix = _elems.size();
			int n_2 = _elems[ix-2];
			int n_1 = _elems[ix-1];
			for(; ix < pos; ++ix)
			{
				int elem = n_2 + n_1;
				_elems.push_back(elem);
				n_2 = n_1; n_1 = elem;
			}
		}
}

int main()
{
	cout << "Hello, a Derived Class!\n";

	num_sequence *ps = new Fibonacci(12, 8);

	// ok: invokes Fibonacci::what_am_i() through virtual mechanism
	ps->what_am_i();

	// ok: invokes inherited num_sequence::max_elems();
	ps->max_elems();

	// error: length() is not part of num_sequence interface
	// ps->length();

	// ok: invokes Fibonacci destructor through virtual mechanism
	delete ps;
}
