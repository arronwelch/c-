// 4.6.cpp: Building an Iterator Class


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

// class Triangular_iterator;
class Triangular_iterator {
	//friend int operator*(const Triangular_iterator &rhs);
public:
	// set _index to index-1 in order not to substract 1 with
	// each element access ...
	Triangular_iterator(int index) : _index(index-1) {}
	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*() const;
	int& operator++();		// prefix version
	int operator++(int);	// postfix version
	int index() { return _index; }
	int iterator_overflow() const;
private:
	void check_integrity() const;
	int _index;
};

class Triangular {
	// confers friendship on all the
	// member functions of Triangular_iterator
	friend class Triangular_iterator;
	// This form of class friendship does not require that the definition 
	// of the class be seen before the friend declaration.
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
	// this shields users from having to know
	// the actual name of the iterator class ...
	typedef Triangular_iterator iterator;

	Triangular_iterator begin() const
	{
		return Triangular_iterator(_beg_pos);
	}

	Triangular_iterator end() const
	{
		return Triangular_iterator(_beg_pos+_length);
	}
	//friend int Triangular_iterator::operator*(const Triangular_iterator &rhs);
	//friend void Triangular_iterator::check_integrity();
	
	int length() const	{ return _length; }
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

// Triangular trian(1, 8);
// 
// Triangular::iterator
// 			it = trian.begin(),
// 			end_it = trian.end();
// 
// while (it != end_it)
// {
// 	cout << *it << ' ';
// 	++it;
// }

// class Triangular_iterator {
// public:
// 	// set _index to index-1 in order not to substract 1 with
// 	// each element access ...
// 	Triangular_iterator(int index) : _index(index-1) {}
// 	bool operator==(const Triangular_iterator&) const;
// 	bool operator!=(const Triangular_iterator&) const;
// 	int operator*() const;
// 	int& operator++();		// prefix version
// 	int operator++(int);	// postfix version
// 	int index() { return _index; }
// 	friend int operator*(const Triangular_iterator &rhs);
// private:
// 	void check_integrity() const;
// 	int _index;
// };

inline bool Triangular_iterator::
operator==(const Triangular_iterator &rhs) const
	{ return _index == rhs._index; }

inline bool Triangular_iterator::
operator!=(const Triangular_iterator &rhs) const
	{ return !(*this == rhs); }

// An operator can be defined either as a member operator function,
inline int Triangular_iterator::
operator*() const
{
	check_integrity();
	return Triangular::_elems[_index];
}

inline int Triangular_iterator::
iterator_overflow() const
{
	return 0;
}
// or as a nonmember operator function,
// inline int
// operator*(const Triangular_iterator &rhs)
// {
// 	rhs.check_integrity();
// 
// 	// note: teh non-member instance has
// 	// no access privilege to nonpublic members
// 	return Triangular::_elems[rhs.index()];
// }

inline void Triangular_iterator::
check_integrity() const
{
	// we'll look at the throw expression in Chapter 7 ...
	if (_index > Triangular::_max_elems)
		throw iterator_overflow();

	// grow vector if necessary ...
	if (_index > Triangular::_elems.size())
		Triangular::gen_elements(_index);
}

inline int& Triangular_iterator::
operator++()
{	// prefix instance(++trian)
	++_index;
	check_integrity();
	return Triangular::_elems[_index];
}

inline int Triangular_iterator::
operator++(int)
{
	// postfix instance(trian++)
	check_integrity();
	return Triangular::_elems[_index++];
}

int main()
{
	cout << "Hello, Iterator Class!\n";

	Triangular tri(20);
	Triangular::iterator it = tri.begin();
	Triangular::iterator end_it = tri.end();

	cout << "Triangular Series of " << tri.length() << " elements\n";
	while (it != end_it)
	{
		cout << *it << ' ';
		++it;
	}
	cout << '\n';
}
