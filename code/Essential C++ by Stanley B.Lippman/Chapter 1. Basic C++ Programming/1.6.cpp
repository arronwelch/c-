// 1.6 Pointers Allow for Flexibility

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // c language stdlib

using namespace std;

int main(void)
{
	int ival = 1024; // To define a pointer of a particular type,
					 // we follow the type name with an asterisk
	// int *pi; // pi is a pointer to an object of type int
	ival;  // evaluates to the value of ival
	&ival; // evaluates to the address of ival
	int *pi = &ival;

	// dereference pi to access the object it addresses
	if (*pi != 1024) // read
		*pi = 1023;	 // write

	pi;	 // evaluates to the address held by pi
	*pi; // evaluates to the value of the object addressed by pi

	// initialize each pointer to address no object
	pi = 0;
	int *pi_copy = 0;
	double *pd = 0;
	string *ps = 0;

	if (pi && *pi != 1024)
		*pi = 1024;

	if (!pi) // true if pi is set to 0
		cout << "pi is 0!\n";

	vector<int> fibonacci, lucas, pell, triangular, square, pentagonal;

	// type_of_object_pointed_to * name_of_pointer_object
	vector<int> *pv = 0;

	pv = &fibonacci;
	// ...
	pv = &lucas;

	const int seq_cnt = 6;

	// an array of seq_cnt pointers to
	//    objects of type vector<int>
	vector<int> *seq_addres[seq_cnt] = {
		&fibonacci, &lucas, &pell,
		&triangular, &square, &pentagonal};

	vector<int> *current_vec = 0;
	// ...
	for (int ix = 0; ix < seq_cnt; ix++)
	{
		current_vec = seq_addres[ix];
		// all element diaplay is implemented
		// indirectly through current_vec
	}

	srand(seq_cnt);
	int seq_index = rand() % seq_cnt;
	current_vec = seq_addres[seq_index];

	if (!fibonacci.empty() &&
		(fibonacci[1] == 1))
		cout << "fibonacci[1] == 1\n";

	if (pv && pv->empty() && ((*pv)[1] == 1))
		cout << "(*pv)[1] == 1\n";

	cout << "go to the end!\n";
}
