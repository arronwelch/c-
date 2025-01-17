// 4.2.cpp: What Are Class Constructors and the Class Destructor?

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Triangular {
public:
	// overloaded set of constructors
	//Triangular();	// default constructor
	//Triangular(int len);
	//Triangular(int len, int bp);

	// also a default constructor
	Triangular(int len = 1, int bp = 1);

	Triangular(const Triangular&);

private:
	string _name;
	int _length;	// number of elements
	int _beg_pos;	// beginning position of range
	int _next;		// next element to iterate over
};

// Triangular::Triangular()
// {
// 	_length = 1;
// 	_beg_pos = 1;
// 	_next = _beg_pos - 1;
// }
// 
// Triangular::Triangular(int len)
// 	: _name("Triangular")
// {
// 	// _length and _beg_pos both must be at least 1
// 	// best not to trust the user to always be right
// 	_length = len > 0 ? len : 1;
// 	_beg_pos = 1;
// 	_next = _beg_pos - 1;
// }

Triangular::Triangular(int len, int bp)
	: _name("Triangular")
{
	// _length and _beg_pos both must be at least 1
	// best not to trust the user to always be right
	_length = len > 0 ? len : 1;
	_beg_pos = bp > 0 ? bp : 1;
	_next = _beg_pos - 1;
}

// The Member Initialization List
Triangular::Triangular(const Triangular &rhs)
	: _name("Triangular"),
	  _length (rhs._length),
	  _beg_pos(rhs._beg_pos),_next(rhs._beg_pos-1)
{} // yes, empty!

// a destructor is a user-defined class member function:
class Matrix {
public:
	Matrix(int row, int col)
		: _row(row), _col(col)
	{
		// constructor allocates a resource
		// note: no error checking is shown
		_pmat = new double[row * col];
	}
	Matrix(const Matrix&);

	~Matrix()
	{
		// destructor frees the resource
		delete [] _pmat;
	}

	// ...

private:
	int _row, _col;
	double *_pmat;
};

Matrix::Matrix(const Matrix &rhs)
	: _row(rhs._row), _col(rhs._col)
{	// create a "deep copy" of the array addressed by rhs._pmat
	// what should go here?
	int elem_cnt = _row * _col;
	_pmat = new double[elem_cnt];

	for (int ix = 0; ix < elem_cnt; ++ix)
		_pmat[ix] = rhs._pmat[ix];
}

int main()
{
	Triangular tri1;
	Triangular tri2(2);
	Triangular tri3(3,3);
	Triangular tri4(tri3);
	cout << "Hello, Constructors!\n";

	Matrix mat(4,4);
	// constructor applied here
	{
		Matrix mat2 = mat;
		// default memberwise copy applied
		// ... use mat2 here
		// destructor applied here for mat2
		cout << "Hello, Destructor for mat2!\n";
	}

	// ... use mat here

	cout << "Hello, Destructor for mat!\n";
	// destructor applied here for mat
}
