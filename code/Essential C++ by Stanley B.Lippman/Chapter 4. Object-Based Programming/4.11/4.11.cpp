// 4.11.cpp: Pointers to Class Member Functions

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class num_sequence {
public:
	typedef void (num_sequence::*PtrType) (int);
	int elem(int pos);
	bool check_integrity(int elem);

	// _pmf addresses one of these
	void fibonacci(int);
	void pell(int);
	void lucas(int);
	void triangular(int);
	void square(int);
	void pentagonal(int);
	// ...
private:
	vector<int>* _elem;				// points to the current vector
	PtrType _pmf;					// points to the current algorithm
	static const int num_seq = 7;	// !
	static PtrType func_tbl[num_seq];
	static vector<vector<int> > seq;
};

const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq);

typedef num_sequence::PtrType PtrType;

num_sequence::PtrType
	num_sequence::func_tbl[num_seq] =
	{	0,
		&num_sequence::fibonacci,
		&num_sequence::pell,
		&num_sequence::lucas,
		&num_sequence::triangular,
		&num_sequence::square,
		&num_sequence::pentagonal
	};

int num_sequence::elem(int pos)
{
	if (! check_integrity(pos))
		return 0;

	if (pos > _elem->size())
		(this->*_pmf) (pos-1);

	return (*_elem)[pos-1];
}

int main()
{
	// num_sequence ns;
	 const int pos = 8;
	// for (int ix = 1; ix < num_sequence::num_of_sequences(); ++ix)
	// {
	// 	ns.set_sequence(num_sequence::nstype(ix));
	// 	int elem_val = ns.elem(pos);
	// 	display(cout, ns, pos, elem_val);
	// }

	cout << "Hello, Pointer to Class Member Functions!\n";

	num_sequence ns;
	num_sequence *pns = &ns;
	PtrType pm = &num_sequence::fibonacci;

	// equivalent to ns.fibonacci(pos)
	(ns.*pm)(pos);

	// equivalent to pns->fibonacci(pos)
	(pns->*pm)(pos);
}
