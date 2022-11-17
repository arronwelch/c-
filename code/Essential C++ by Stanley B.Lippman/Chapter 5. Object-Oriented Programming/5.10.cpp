// 5.10.cpp: Run-Time Type Identification

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

// num_sequence.h
class num_sequence {
public:
	virtual ~num_sequence() {}
	inline const char* what_am_i() const
		{ return typeid(*this).name(); }

	int elem(int pos) const;
	ostream& print(ostream &os = cout) const;

	int length() const { return _length; }
	int beg_pos() const { return _beg_pos; }
	static int max_elems() { return _max_elems; }
	string name() const { return _name; }

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos, int size) const;

	num_sequence(int len, int bp, vector<int> &re, const char* name)
		: _length(len), _beg_pos(bp), _relems(re), _name(name) {}

	int _length;
	int _beg_pos;
	vector<int> & _relems;
	string _name;

	const static int _max_elems = 1024;
};

// num_sequence.cpp
int num_sequence::
elem(int pos) const
{
	if (! check_integrity(pos, _relems.size()))
		return 0;

	if (pos > _relems.size())
		gen_elems(pos);

	return _relems[pos-1];
}

ostream& num_sequence::
print(ostream &os) const
{
	int elem_pos = _beg_pos-1;
	int end_pos = elem_pos + _length;

	if (end_pos > _relems.size())
		gen_elems(end_pos);

	os << '(' << _beg_pos << " , " << _length << ") ";

	while (elem_pos < end_pos)
		os << _relems[elem_pos++] << ' ';

	return os;
}

bool num_sequence::
check_integrity(int pos, int size) const
{
	if (pos <= 0 || pos > _max_elems)
	{
		cerr << "!! invalid position: " << pos
			<< " Cannot honor request!\n";
		return false;
	}

	if ( pos > size)
		// gen_elems() is invoked through virtual mechanism
		gen_elems(pos);

	return true;
}

ostream& operator<<(ostream &os, const num_sequence &ns)
	{ return ns.print(os); }

// Fibonacci.h
class Fibonacci : public num_sequence {
public:
	Fibonacci(int len = 1, int beg_pos = 1)
		: num_sequence(len, beg_pos, _elems, "Fibonacci") {}
//	virtual const char* what_am_i() const
//		{ return "Fibonacci"; }
	virtual void gen_elems(int pos) const;

protected:
//	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};
vector<int> Fibonacci::_elems;

// Fibonacci.cpp
void Fibonacci::gen_elems(int pos) const
{
	if (_elems.empty())
	{
		_elems.push_back(1);
		cout << "gen_elems: " << 1 << endl;
		_elems.push_back(1);
		cout << "gen_elems: " << 1 << endl;
	}

	if (_elems.size() < pos)
	{
		int ix = _elems.size();
		int n_2 = _elems[ix-2];
		int n_1 = _elems[ix-1];

		for(; ix < pos; ++ix)
		{
			int elem = n_2 + n_1;
			_elems.push_back(elem);
			cout << "gen_elems: " << elem << endl;
			n_2 = n_1; n_1 = elem;
		}
	}
}

int main()
{
	Fibonacci fib(12, 8);

	num_sequence *ns = &fib;

	cout << *ns << endl;

	num_sequence *ps = &fib;
	// ...
	if (typeid(*ps) == typeid(Fibonacci))
		// ok, ps addresses a Fibonacci class object
	// ps->gen_elems(64);

	// error: ps is not a pointer to Fibonacci
	// although we know it currently addresses
	// a Fibonacci class object
//	ps->Fibonacci::gen_elems(64);

	cout << *ps << endl;

	if (typeid(*ps) == typeid(Fibonacci))
	{
		Fibonacci *pf = static_cast<Fibonacci*>(ps);
		pf->gen_elems(13);
		cout << *pf << endl;
	}

	if (Fibonacci *pf = dynamic_cast<Fibonacci*>(ps))
	{
		pf->gen_elems(14);
		cout << *pf << endl;
	}
}
