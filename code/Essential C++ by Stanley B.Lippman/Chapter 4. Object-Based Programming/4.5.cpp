// 4.5.cpp: Static Class Members

class Triangular {
public:
	// ...
private:
	static vector<int> _elems;
};

// placed in program text file, such as Triangular.cpp
vector<int> Triangular::_elems;

int Triangular::_initial_size = 8;

Triangular::Triangular(int len, int beg_pos)
	: _length(len > 0 ? len : 1),
	  _beg_pos(beg_pos > 0 ? beg_pos : 1)
{
	_next = _beg_pos - 1;
	int elem_cnt = _beg_pos + _length;

	if (_elems.size() < elem_cnt)
		gen_elements(elem_cnt);
}

class intBuffer {
public:
	// ...
private:
	static const int _buf_size = 1024;	// ok
	int _buffer[_buf_size];				// ok
};
