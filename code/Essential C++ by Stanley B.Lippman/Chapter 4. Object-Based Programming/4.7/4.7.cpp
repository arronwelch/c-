// 4.7.cpp: Collaboration Sometimes Requires Friendship

#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::cerr;

// class Triangular_iterator;
class Triangular_iterator {
public:
	friend int operator*(const Triangular_iterator &rhs);
	// ...
	int index() const { return _index; }
	bool iterator_overflow() const;
private:
	void check_integrity() const;
	int _index;
};
// class Triangular;

class Triangular {
public:
	static int elems_size() { return _elems.size(); }
	static int max_elems() { return _max_elems; }
	static void gen_elements(int length);
	static vector<int> _elems;
private:
	static const int _max_elems = 1024;
};

void Triangular::
gen_elements(int length)
{
	if ( length < 0 || length > _max_elems)
	{
		// issue error message and return
		cerr << "length: " << length << " is less than 0 or large than _max_elems(" << _max_elems
			 << "!\n";
		return;
	}

	if (_elems.size() < length)
	{
		int ix = _elems.size() ? _elems.size()+1 : 1;
		for (; ix <= length-1; ++ix)
			_elems.push_back(ix*(ix+1)/2);
	}
}

vector<int> Triangular::_elems;


// no longer needs to be a friend
inline void Triangular_iterator::
check_integrity() const
{
	if (_index > Triangular::max_elems())
		throw iterator_overflow();

	if (_index < Triangular::elems_size())
		Triangular::gen_elements(_index);
}

inline int operator*(const Triangular_iterator &rhs)
{
	rhs.check_integrity();
	return Triangular::_elems[rhs.index()];
}

int main()
{
	cout << "Hello, friend!\n";
}
