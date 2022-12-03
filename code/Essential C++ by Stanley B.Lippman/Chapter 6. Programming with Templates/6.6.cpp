/* 6.6 Constant Expressions and Default Parameters */

#include <iostream>
#include <vector>

using namespace std;

// the num_sequence class definition
// we no longer need to store as data members
// the length and beginning position

template <int len, int beg_pos>
class num_sequence {
public:
	virtual ~num_sequence() {};
	int elem(int pos) const;
	const char* what_am_i() const;
	static int max_elems() { return _max_elems; }
	ostream& print(ostream &os = cout) const;
protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos, int size) const;

	num_sequence(vector<int> *pe) : _pelems(pe) {}
	static const int _max_elems = 1024;
	vector<int> *_pelems;
};

// function template output operator definition
template <int len, int beg_pos> ostream&
operator<<(ostream &os, const num_sequence<len,beg_pos> &ns)
	{ return ns.print(os); }

// num_sequence member functions ...
template <int len, int beg_pos>
int num_sequence<len, beg_pos>::
elem(int pos) const
{
	if (! check_integrity(pos, _pelems->size()))
		return 0;

	return (*_pelems)[pos-1];
}

template <int length, int beg_pos>
const char* num_sequence<length, beg_pos>::
what_am_i() const
	{ return typeid(*this).name(); }

template <int length, int beg_pos>
bool num_sequence<length, beg_pos>::
check_integrity(int pos, int size) const
{
	if (pos < 0 || pos > max_elems()) {
		cerr << "!! invalid position: " << pos
			 << " Cannot honor request\n";
		return false;
	}

	if (pos > size) gen_elems(pos);
	return true;
}

template <int length, int beg_pos>
ostream& num_sequence<length, beg_pos>::
print(ostream &os) const
{
	int elem_pos = beg_pos - 1;
	int end_pos = elem_pos + length;

	if (! check_integrity(end_pos, _pelems->size()))
		return os;

	os << "("
	   << beg_pos << " , "
	   << length << ") ";

	while (elem_pos < end_pos)
		os << (*_pelems)[elem_pos++] << ' ';
	return os;
}

// ok: the Fibonacci class template with default parameter value
template <int length, int beg_pos=1>
class Fibonacci : public num_sequence<length, beg_pos> {
public:
	Fibonacci() : num_sequence<length, beg_pos>(&_elems) {}
protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};

// declare the static data member template for Fibonacci
template <int length, int beg_pos>
vector<int> Fibonacci<length, beg_pos>::_elems;

// the Fibonacci class template member functions
template <int length, int beg_pos>
void Fibonacci<length, beg_pos>::
gen_elems(int pos) const
{
	if (pos <= 0 || pos > num_sequence<length, beg_pos>::max_elems())
		return;

	if (_elems.empty())
	{
		_elems.push_back(1);
		_elems.push_back(1);
	}

	if (_elems.size() < pos)
	{
		int ix = _elems.size();
		int n_2 = _elems[ix-2];
		int n_1 = _elems[ix-1];

		int elem;
		for (; ix < pos; ++ix)
		{
			elem = n_2 + n_1;
			_elems.push_back(elem);
			n_2 = n_1; n_1 = elem;
		}
	}
}

int main()
{
	Fibonacci<8> fib1;
	Fibonacci<8, 8> fib2;
	Fibonacci<12, 8> fib3;

	cout << "fib1: " << fib1 << '\n'
		 << "fib2: " << fib2 << '\n'
		 << "fib3: " << fib3 << endl;
}

template <void (*pf)(int pos, vector<int> &seq)>
class numeric_sequence
{
public:
	numeric_sequence(int len, int beg_pos = 1)
	{
		// sanity check that pf is non-null ...
		if (! pf)
			// issue error message and bail out
			cerr << "error pointer to func!" << endl;

		_len = len > 0 ? len : 1;
		_beg_pos = beg_pos > 0 ? beg_pos : 1;

		pf(beg_pos+len, _elems);
	}
	// ...
private:
	int _len;
	int _beg_pos;
	vector<int> _elems;
};

// void fibonacci(int pos, vector<int> &seq);
// void pell(int pos, vector<int> &seq);
// // ...
// numeric_sequence<fibonacci> ns_fib(12);
// numeric_sequence<pell> ns_pell(18, 8);
