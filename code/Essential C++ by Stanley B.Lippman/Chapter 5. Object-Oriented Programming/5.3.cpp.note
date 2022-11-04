// 5.3 Polymorphism without Inheritance

for (int ix = 1; ix < num_sequence::num_of_sequences(); ++ix)
{
	ns.set_sequence(num_sequence::nstype(ix));
	int elem_val = ns.elem(pos);
	// ...
}

class num_sequence {
public:
	enum ns_type {
		ns_unset, ns_fibonacci, ns_pell, ns_lucas,
		ns_triangular, ns_square, ns_pentagonal
	};

	static ns_type nstype(int num)
	{
		return num <= 0 || num >= num_seq
			? ns_unset // invalid value
			: static_cast< ns_type >(num);
	}
	// ...

private:
	vector<int> *_elem;		// addresses current element vector
	PtrType		 _pmf;		// addresses current element generator
	ns_type		 _isa;		// identifies current sequence type
	// ...
};

ns.set_sequence(num_sequence::nstype(ix));

void num_sequence::
set_sequence(ns_type nst)
{
	switch (nst)
	{
		default:
			cerr << "invalid type: setting to 0\n";
			// deliberate fall-through

		case ns_unset:
			_pmf = 0;
			_elem = 0;
			_isa = ns_unset;
			break;

		case ns_fibonacci:	case ns_pell:	case ns_lucas:
		case ns_triangular:	case ns_square:	case ns_pentagonal:
			// func_tbl: table of pointer to member functions
			// seq: vector of vectors holding sequence elements
			_pmf = func_tbl[nst];
			_elem = &seq[nst];
			_isa = nst;
			break;
	}
}

inline void display(ostream &os, const num_sequence &ns,int pos)
{
	os << "The element at position "
		<< pos << " for the "
		<< ns.what_am_i() << " sequence is "
		<< ns.elem(pos) << endl;
}

const char* num_sequence::
what_am_i() const
{
	static char *names[num_seq] = {
			"notSet",
			"fibonacci", "pell",
			"lucas", "triangular",
			"square", "pentagonal"
	};
	return names[_isa];
}
