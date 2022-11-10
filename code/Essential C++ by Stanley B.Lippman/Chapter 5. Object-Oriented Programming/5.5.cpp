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
	bool check_integrity(int pos) const;
	virtual void gen_elems(int pos) const;
	int _length;
	int _beg_pos;
	static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

int Fibonacci::
elem(int pos) const
{
	// now resolves to Fibonacci's instance
	if (! check_integrity(pos))
		return 0;

	if (pos > _elems.size())
		Fibonacci::gen_elems(pos);

	return _elems[pos-1];
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

ostream& Fibonacci::
print(ostream &os) const
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

	if (end_pos > _elems.size())
		Fibonacci::gen_elems(end_pos);

	while (elem_pos < end_pos)
		os << _elems[elem_pos++] << ' ';

	return os;
}

inline bool Fibonacci::
check_integrity(int pos) const
{
	// class scope operator necessary ...
	// unqualified name resolves to this instance!
	if (! num_sequence::check_integrity(pos))
		return false;

	if (pos > _elems.size())
		Fibonacci::gen_elems(pos);

	return true;
}

int main()
{
	cout << "Hello, a Derived Class!\n";

	num_sequence *ps = new Fibonacci(12, 8);
	cout << "new Fibonacci(12, 8)\n";

	cout << "Fibonacci(8) = " << ps->elem(8) << endl;

	// ok: invokes Fibonacci::what_am_i() through virtual mechanism
	cout << "ps->what_am_i() : "
		<< ps->what_am_i()
		<< endl;

	// ok: invokes inherited num_sequence::max_elems();
	cout << "ps->max_elems() : "
		<< ps->max_elems()
		<< endl;

	cout << "display *ps:\n";
	cout << *ps << endl;

	// error: length() is not part of num_sequence interface
	// ps->length();

	// ok: invokes Fibonacci destructor through virtual mechanism
	delete ps;
}
