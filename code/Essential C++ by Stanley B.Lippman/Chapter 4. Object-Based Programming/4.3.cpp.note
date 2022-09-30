// 4.3.cpp : What Are mutable and const ?

int sum(const Triangular &trian)
{
	int beg_pos = trian.beg_pos();
	int length = trian.length();
	int sum = 0;
	for (int ix = 0; ix < length; ++ix)
		sum += trian.elem(beg_pos+ix);
	return sum;
}

class Triangular {
public:
	// const member functions
	int length()	const { return _length; }
	int beg_pos()	const { return _beg_pos; }
	int elem(int pos) const;

	// non-const member functions
	bool next(int &val);
	void next_reset() { _next = _beg_pos - 1; }

	// ...
private:
	int _length;	// number of elements
	int _beg_pos;	// beginning position of range
	int _next;		// next element to iterate over

	// static data members are covered in Section 4.5
	static vector<int> _elems;
};

int Triangular::elem(int pos) const
	{ return _elems[pos-1]; }

bool Triangular::next(int &value) const
{
	if ( _next < _beg_pos + _length - 1)
	{
		// error: modifying _next
		value = _elems[_next++];
		return true;
	}
	return false;
}

class val_class {
public:
	val_class(const BigClass &v)
		: _val(v) {}

	// is this ok?
	BigClass& val() const { return _val; }

private:
	BigClass _val;
};

class val_class {
public:
	const BigClass& val() const { return _val; }
	BigClass& val() { return _val; }
	// ...
};

// For a non-const class object, the non-const instance of val() is invoked.
// For a const class object, the const instance is invoked. For example,
void example(const BigClass *pbc, BigClass &rbc)
{
	pbc->val();		// invokes const instance
	rbc.val();		// invokes non-const instance
	// ...
}

// Mutable Data Member
int sum(const Triangular &trian)
{
	if (! trian.length())
		return 0;

	int val, sum = 0;
	trian.next_reset();
	while (trian.next(val))
		sum += val;

	return sum;
}

// Will this code compile?No, at least not yet.

class Triangular {
public:
	bool next(int &val) const;
	void next_reset() const { _next = _beg_pos - 1; }
	// ...

private:
	mutable int _next;
	int _beg_pos;
	int _length;
};

// next() and next_reset() can now modify _next and still be declared as const member
// functions, allowing our alternative implementation of sum().

int main()
{
	Triangular tri(4);
	cout << tri << " -- sum of elements: "
		 << sum(tri) << endl;

	Triangular tri2(4, 3);
	cout << tri2 << " -- sum of elements: "
		 << sum(tri2) << endl;

	Triangular tri3(4, 8);
	cout << tri3 << " -- sum of elements: "
		 << sum(tri3) << endl;

	return 0;
}
