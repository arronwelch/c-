// 4.3.cpp: What Are mutable and const?

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Triangular;

class Triangular {
public:
	// const member functions
	int length()	const { return _length;		}
	int beg_pos()	const { return _beg_pos;	}
	int elem(int pos) const;

	// non-const member functions
	bool next(int &val) const;
	void next_reset() const { _next = _beg_pos - 1; }

	Triangular(int len = 1, int bp = 1)
	{
		_length = len > 0 ? len : 1;
		_beg_pos = bp > 0 ? bp : 1;
		_next = _beg_pos - 1;
	}

	// ...
private:
	mutable int _next;		// next element to iterate over
	int _length;	// number of elements
	int _beg_pos;	// beginning position of range

	// static data members are covered in Section 4.5
	static vector<int> _elems;
};

// placed in program text file, such as Triangular.cpp
vector<int> Triangular::_elems;

int Triangular::elem(int pos) const
{
	return _elems[pos-1];
}

bool Triangular::next(int &value) const
{
	if (_next < _beg_pos + _length - 1)
	{
		// error: modifying _next
		value = _elems[_next++];
		return true;
	}
	return false;
}

int sum(const Triangular &trian);

int main()
{
	cout << "Hello, mutable!\n";
	Triangular tri(4);
//	cout << tri << " -- sum of elements: "
//		 << sum(tri) << '\n';

	Triangular tri2(4, 3);
//	cout << tri2 << " -- sum of elements: "
//		 << sum(tir2) << '\n';

	Triangular tri3(4, 8);
//	cout << tri3 << " -- sum of elements: "
//		 << sum(tri3) << '\n';

}

// int sum(const Triangular &trian)
// {
// 	int beg_pos = trian.beg_pos();
// 	int length = trian.length();
// 	int sum = 0;
// 	for (int ix = 0; ix < length; ++ix)
// 		sum += trian.elem(beg_pos+ix);
// 	return sum;
// }

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
