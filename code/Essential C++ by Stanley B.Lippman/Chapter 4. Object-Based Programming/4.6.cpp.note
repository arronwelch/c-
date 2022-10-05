// 4.6 Building an Iterator Class

Triangular trian(1, 8);
Triangular::iterator
		it = trian.begin(),
		end_it = trian.end();

while (it != end_it)
{
	cout << *it << ' ';
	++it;
}

class Triangular_iterator
{
public:
// set _index to index-1 in order not to substract 1 with
// each element access ...

	Triangular_iterator(int index) : _index(index-1){}
	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*() const;
	int& operator++();		// prefix version
	int operator++(int);	// postfix version
private:
	void check_integrity() const;
	int _index;
};

inline bool Triangular_iterator::
operator==(const Triangular_iterator &rhs) const
		{ return _index == rhs._index; }

if (trian1 == trian2)
	// ...

if (*ptri1 == *ptri2)
	// ...

inline bool Triangular_iterator::
operator!=(const Triangular_iterator &rhs) const
		{ return !(*this == rhs); }

// An operator can be defined either as a member operator function:
inline int Triangular_iterator::
operator*() const
{
	check_integrity();
	return Triangular::_elems[_index];
}

// or as a nonmember operator function:
inline int
operator*(const Triangular_iterator &rhs)
{
	rhs.check_integrity();

	// note: the non-member instance has no
	// access privilege to nonpublic members
	return Triangular::_elems[rhs._index];
}

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
{	// prefix instance
	++_index;
	check_integrity();
	return Triangular::_elems[_index];
}

inline int Triangular_iterator::
operator++(int)
{
	// postfix instance
	check_integrity();
	return Triangular::_elems[_index++];
}

++it;	// prefix
it++;	// postfix

#include "Triangular_iterator.h"

class Triangular {
public:
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
	// ...

private:
	int _beg_pos;
	int _length;
	// ...
};

// Nested Types

typedef existing_type new_name;

Triangular::iterator it = trian.begin();

iterator it = trian.begin();	// error

Fibonacci::iterator		fit = fib.begin();
Pell::iterator			pit = pel.begin();
vector<int>::iterator	vit = _elems.begin();
string::iterator		sit = file_name.begin();

