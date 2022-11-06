// 5.4.cpp: Defining an Abstract Base Class

#include <iostream>

using namespace std;

class num_sequence {
public:
	virtual ~num_sequence() {};

	// elem(pos): return element at pos
	// gen_elems(pos): generate the elements up to pos
	// what_am_i(): identify the actual sequence
	// print(os): write the elements to os
	// check_integrity(pos): is pos a valid value?
	// max_elems(): returns maximum position supported
	virtual int elem(int pos) const = 0;
	virtual const char* what_am_i() const = 0;
	static int max_elems() { return _max_elems; }
	virtual ostream& print(ostream &os = cout) const = 0;
	// ...

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos) const;

	const static int _max_elems = 1024;
};

bool num_sequence::
check_integrity(int pos) const
{
	if (pos <= 0 || pos > _max_elems)
	{
		cerr << "!! invalid position: " << pos
			<< " Cannot honor request\n";
		return false;
	}
	return true;
}

ostream& operator<<(ostream &os, const num_sequence &ns)
	{ return ns.print(os); }
