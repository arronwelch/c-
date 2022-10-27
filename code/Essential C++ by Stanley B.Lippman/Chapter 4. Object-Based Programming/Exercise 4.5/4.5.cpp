// Exercise 4.5

/*
Implement a 4x4 Matrix class supporting at least the following general interface:addition and
multiplication of two Matrix objects,a print() member function, a compound += operator, and
subscripting supported through a pair of overloaded function call operators,as follows:

float& operator()(int row, int column);
float  operator()(int row, int column) const;

Provide a default constructor taking an optional 16 data values and a constructor taking an array of
16 elements.You do not need a copy constructor, copy assignment operator,or destructor for this
class(these are required in Chapter 6 when we reimplement the Matrix class to support arbitrary
rows and columns).
*/

class Matrix {
public:
	Matrix();
	Matrix& operator+(Matrix&);
	Matrix& operator*(Matrix&);
	void print();
	Matirx& operator+=(Matrix&);
	float& operator()(int row, int column);
	float  operator()(int row, int column);

private:
	int _row;
	int _column;
};
