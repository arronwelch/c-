// 4.5.cpp: Static Class Members

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Triangular {
public:
	// ...
	void my_print(void);
	void my_change(int&);
	Triangular(int len=1, int beg_pos=1);
	int gen_elements(int);
private:
	static vector<int> _elems;
	static int _initial_size;
	int _length;
	int _beg_pos;
	int _next;
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

int Triangular::gen_elements(int cnt)
{
	return 0;
}

int main()
{
	Triangular tri1;
	tri1.my_print(); // print 8
	int val = 16;
	tri1.my_change(val);
	tri1.my_print(); // print 16

	cout << "Hello, Static Class Members!\n";
}
