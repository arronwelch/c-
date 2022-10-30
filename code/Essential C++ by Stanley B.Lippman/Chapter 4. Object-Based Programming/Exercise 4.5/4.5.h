// Exercise 4.5: 4.5.h

/*
Implement a 4x4 Matrix class supporting at least the following general interface: addition
and multiplication of two Matrix objects, a print() member function, a compound +=
operator, and subscripting supported through a pair of overloaded function call operators,
as follows:

float& operator()(int row, int column);
float  operator()(int row, int column) const;

Provide a default constructor taking an optional 16 data values and a constructor taking an
array of 16 elements.You do not need a copy constructor,copy assignment operator,or
desctructor for this class(these are required in Chapter 6 when we reimplement the Matrix
class to support arbitrary rows and columns).
*/

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
using namespace std;

typedef float elemType; // for transition into a template

class Matrix
{
	// friends are not affected by the access level they are
	// declared in. I like to place them at class beginning
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);

public:
	Matrix(const elemType*);
	Matrix(elemType=0.,elemType=0.,elemType=0.,elemType=0.,
			elemType=0.,elemType=0.,elemType=0.,elemType=0.,
			elemType=0.,elemType=0.,elemType=0.,elemType=0.,
			elemType=0.,elemType=0.,elemType=0.,elemType=0.);

	// don't need copy constructor, destructor,
	// or copy assignment operator for the Matrix class

	// simplifies transition to general matrix
	int rows() const { return 4; }
	int cols() const { return 4; }

	ostream& print(ostream&) const;
	void operator+=(const Matrix&);

	elemType operator()(int row, int column) const
		{ return _matrix[row][column]; }

	elemType& operator()(int row, int column)
		{ return _matrix[row][column]; }

private:
	elemType _matrix[4][4];
};

inline ostream& operator<<(ostream& os, const Matrix &m) {
	return m.print(os); }

#endif
