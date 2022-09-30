// 4.4.cpp : What Is the this Pointer?

Triangular tr1(8);
Triangular tr2(8, 9);

tr1.copy(tr2);

Triangular& Triangular::
copy(const Triangular &rhs)
{
	_length = rhs._length;
	_beg_pos = rhs._beg_pos;
	_next = rhs._beg_pos - 1;

	return ??? what exactly ???;
}

// Pseudo Code: Internal Member Function Transformation

Triangular& Triangular::
copy(Triangular *this, const Triangular &rhs)
{
	this->_length = rhs._length;
	this->_beg_pos = rhs._beg_pos;
	this->_next = rhs._beg_pos - 1;
}

// internal code transformation:
// tr1 becomes the class object addressed by the this pointer
copy(&tr1, tr2);

// returns the class object addressed by the this pointer
return *this;

Triangular& Triangular::
copy(const Triangular &rhs)
{
	// check that the two objects are not the same
	if (this != &rhs)
	{
		_length = rhs._length;
		_beg_pos = rhs._beg_pos;
		_next = rhs._beg_pos - 1;
	}

	return *this;
}
