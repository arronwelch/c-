// 4.8.cpp: Implementing a Copy Assignment Operator

#include <iostream>

using std::cout;

class Matrix {
public:
	Matrix(int row, int col)
		: _row(row), _col(col)
	{
		// constructor allocates a resource
		// note: no error checking is shown
		_pmat = new double[row * col];
	}
	Matrix(const Matrix &rhs);
	Matrix& operator=(const Matrix &rhs);
	void display() {
		for(int ix = 0; ix < _row*_col; ++ix)
			cout << _pmat[ix] << ' ';
		cout << '\n';
	}

	~Matrix()
	{
		// destructor frees the resource
		delete [] _pmat;
	}

private:
	int		_row, _col;
	double	*_pmat;
};

Matrix::Matrix(const Matrix &rhs)
	: _row(rhs._row), _col(rhs._col)
{	// create a "deep copy" of the array addressed by rhs._pmat
	int elem_cnt = _row * _col;
	_pmat = new double[elem_cnt];

	for(int ix = 0; ix < elem_cnt; ++ix)
		_pmat[ix] = rhs._pmat[ix];
}

Matrix& Matrix::operator=(const Matrix &rhs)
{
	if (this != &rhs)
	{
		_row = rhs._row; _col = rhs._col;
		int elem_cnt = _row * _col;

		delete [] _pmat;
		_pmat = new double[elem_cnt];
		for (int ix = 0; ix < elem_cnt; ++ix)
			_pmat[ix] = rhs._pmat[ix];
	}
	return *this;
}

int main()
{
	Matrix mat(4, 4);
	Matrix mat2(3, 2);
	mat2.display();
	mat2 = mat;
	mat2.display();

	cout << "Hello, Copy Assignment Operator!\n";
}
