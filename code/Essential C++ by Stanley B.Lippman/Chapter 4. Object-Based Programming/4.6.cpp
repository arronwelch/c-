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
operator==(const Triangular_iterator $rhs) const
		{ return _index == rhs._index; }

if (trian1 == trian2)
	// ...

if (*ptri1 == *ptri2)
	// ...

inline bool Triangular_iterator::
operator!=(const Triangular_iterator &rhs) const
		{ return !(*this == rhs); }
