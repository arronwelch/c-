// 4.10.cpp: Providing Class Instances of the iostream Operators

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::ostream;
using std::vector;
using std::find;
using std::istream;
using std::cin;

class Triangular {
public:
	Triangular(int beg_pos=1, int length=1);
	int beg_pos() const { return _beg_pos; }
	int length() const { return _length; }
	int elem(int pos) const;

	void beg_pos(int bp) 
	{
		_beg_pos = bp > 0 ? bp : 1;
	}
	bool length(int len)
	{
		if (len > _max_elems)
		{
			cerr << "length over the max_elems!\n";
			return false;
		}
		_length = len > 0 ? len : 1;
		int elem_cnt = _beg_pos + _length;
		if ( _elems.size() < elem_cnt)
			gen_elements(elem_cnt);
		return true;
	}

	bool next(int &val) const;
	void next_reset() { _next = _beg_pos - 1; }

	static bool is_elem(int);
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	static void display(int len, int bp, ostream &os = cout);

private:
	int _beg_pos;
	int _length;
	mutable int _next;
	static vector<int> _elems;
	static const int _max_elems = 1024;
};

vector<int> Triangular::_elems;

int Triangular::elem(int pos) const
	{ return _elems[pos-1]; }

bool Triangular::next(int &value) const
{
	if (_next < _beg_pos + _length - 1)
	{
		// error: modifying _next
		value = _elems[_next+1];
		return true;
	}
	return false;
}

Triangular::Triangular(int len, int beg_pos)
	: _length(len > 0 ? len : 1),
	  _beg_pos(beg_pos > 0 ? beg_pos : 1)
{
	_next = _beg_pos-1;
	int elem_cnt = _beg_pos + _length;

	if (_elems.size() < elem_cnt)
		gen_elements(elem_cnt);
}

bool Triangular::
is_elem(int value)
{
	if (! _elems.size() ||
		_elems[_elems.size()-1] < value)
			gen_elems_to_value(value);

	vector<int>::iterator found_it;
	vector<int>::iterator end_it = _elems.end();

	found_it = find(_elems.begin(), end_it, value);
	return found_it != end_it;
}

void Triangular::
gen_elements(int length)
{
	if (length < 0 || length > _max_elems) {
		// issue error message and return
		cerr << " issue error message and return" << endl;
		return;
	}

	if (_elems.size() < length)
	{
		int ix = _elems.size() ? _elems.size()+1 : 1;
		for(; ix <= length-1; ++ix)
			_elems.push_back(ix*(ix+1)/2);
	}
}

void Triangular::
gen_elems_to_value(int value)
{
	int ix = _elems.size();
	if (! ix)
	{
		_elems.push_back(1);
		ix = 1;
	}

	while (_elems[ix-1] < value &&
			ix < _max_elems)
	{
		// cout << "elems to value: " << ix*(ix+1)/2 << endl;
		_elems.push_back(ix*(ix+1)/2);
		++ix;
	}

	if (ix == _max_elems)
		cerr << "Triangular Sequence: oops: value too large "
			 << value << " -- exceeds max size of "
			 << _max_elems << endl;
}

void Triangular::
display(int len, int bp, ostream &os)
{
	int elem_cnt = bp + len -1;
	for(int ix = bp-1; ix < elem_cnt; ++ix)
		os << _elems[ix] << ' ';
	os << endl;
}

ostream&
operator<<(ostream &os, const Triangular &rhs)
{
	os << "(" << rhs.beg_pos() << ", "
	   << rhs.length() << ") ";

	rhs.display(rhs.length(), rhs.beg_pos(), os);
	return os;
}

istream&
operator>>(istream &is, Triangular &rhs)
{
	char ch1, ch2;
	int bp, len;

	// given the input: (3 , 6) 6 10 15 21 28 36
	// ch1 == '(', bp == 3, ch2 == ',', len == 6
	is >> ch1 >> bp
	   >> ch2 >> len;

	// set the three data member of rhs ...
	rhs.beg_pos(bp);
	rhs.length(len);
	rhs.next_reset();

	return is;
}

int main()
{
	Triangular tri(6, 3);
	cout << tri << '\n';

	cout << "Please enter new Triangular(beg_pos,length):\n";
	Triangular tri2;
	cin >> tri2;

	// let's see what we got ...
	cout << tri2;
	cout << "Hello, Instances of the iostream Operators!\n";
}
