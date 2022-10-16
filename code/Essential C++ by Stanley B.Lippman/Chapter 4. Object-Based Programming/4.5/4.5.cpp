// 4.5.cpp: Static Class Members

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::find;
using std::ostream;
using std::cerr;
using std::endl;
using std::cin;

class Triangular {
public:
	// ...
	void my_print(void);
	void my_change(int&);
	Triangular(int len=1, int beg_pos=1);
	static bool is_elem(int);
	static void gen_elements(int length);
	static void gen_elems_to_value(int value);
	static void display(int len, int beg_pos, ostream &os = cout);
	// ...
private:
	static vector<int> _elems;
	static int _initial_size;
	int _length;
	int _beg_pos;
	int _next;
	static const int _buf_size = 1024;	// ok
	int _buffer[_buf_size];				// ok
	static const int _max_elems = 1024;
};

// placed in program text file, such as Triangular.cpp
vector<int> Triangular::_elems;

// An initial value, if desired, can also be specified:
int Triangular::_initial_size = 8;

void Triangular::my_print(void)
{
	cout << "_initial_size = " << _initial_size << '\n';
}

void Triangular::my_change(int &val)
{
	_initial_size = val;
}

Triangular::Triangular(int len, int beg_pos)
	: _length(len > 0 ? len : 1),
	  _beg_pos(beg_pos > 0 ? beg_pos : 1)
{
	_next = _beg_pos - 1;
	int elem_cnt = _beg_pos + _length;

	if (_elems.size() < elem_cnt)
		gen_elements(elem_cnt);
}

void Triangular::
gen_elements(int length)
{
	if ( length < 0 || length > _max_elems)
	{
		// issue error message and return
		cerr << "length " << length << " is less than 0 or large than max_elem!\n";
		return;
	}

	if (_elems.size() < length)
	{
		int ix = _elems.size() ? _elems.size()+1 : 1;
		for (; ix <= length-1; ++ix)
			_elems.push_back(ix*(ix+1)/2);
	}
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

// When defined outside the class body, the static keyword is not repeated(this is also true of
// static data members):
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


int main()
{
	Triangular tri1;
	tri1.my_print(); // print 8
	int val = 16;
	tri1.my_change(val);
	tri1.my_print(); // print 16

	cout << "Hello, Static Class Members!\n";

	char ch;
	bool more = true;

	while (more)
	{
		cout << "Enter value: ";
		int ival;
		cin >> ival;

		bool is_elem = Triangular::is_elem(ival);
		cout << ival
			 << (is_elem ? " is " : " is not ")
			 << "an element in the Triangular series.\n"
			 << "Another value? (y/n) ";

		cin >> ch;
		if (ch == 'n' || ch == 'N')
			more = false;
	}
}
