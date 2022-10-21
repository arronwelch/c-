// 4.10.cpp: Providing Class Instances of the iostream Operators

#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::vector;

class Triangular {
public:
	Triangular(int beg_pos=1, int length=1) 
	{
		_beg_pos = beg_pos > 0 ? beg_pos : 1;
		_length = length > 0 ? length : 1;
		_next = _beg_pos-1;
	}
	int beg_pos() const { return _beg_pos; }
	int length() const { return _length; }
	void display(int len, int bp, ostream& os) const;

private:
	int _beg_pos;
	int _length;
	int _next;
	static vector<int> _elems;
};

vector<int> Triangular::_elems;

void Triangular::display(int len, int bp, ostream& os) const
{
	
}

ostream& 
operator<<(ostream &os, const Triangular &rhs)
{
	os << "(" << rhs.beg_pos() << ", "
	   << rhs.length() << ") ";

	rhs.display(rhs.length(), rhs.beg_pos(), os);
	return os;
}

int main()
{
	cout << "Hello, Instances of the iostream Operators!\n";
}
