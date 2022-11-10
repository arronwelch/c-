// 5.6.cpp: Using an Inheritance Hierarchy

inline void display(ostream &os,
					const num_sequence &ns, int pos)
{
	os << "The element at position "
		<< pos				<< " for the "
		<< ns.what_am_i()	<< " sequence is "
		<< ns.elem(pos)		<< endl;
}

int main()
{
	const int pos = 8;

	Fibonacci fib;
	display(cout, fib, pos);

	Pell pell;
	display(cout, pell, pos);

	Lucas lucas;
	display(cout, lucas, pos);

	Triangular trian;
	display(cout, trian, pos);

	Square square;
	display(cout, trian, pos);

	Pentagonal penta;
	display(cout, penta, pos);
}
