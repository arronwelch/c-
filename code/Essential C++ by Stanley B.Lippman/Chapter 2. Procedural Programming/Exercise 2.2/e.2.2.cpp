/* Exercise 2.2: e.2.2.cpp */

/*
 * The formula for the Pentagonal numeric sequence is Pn=n*(3n-1)/2. This yields the sequence
 * 1, 5, 12, 22, 35, and so on. Define a function to fill a vector of elements passed in to the
 * function calculated to some user-specified position. Be sure to verify that the position
 * specified is valid. Write a second function the type of numeric series the vector represents.
 * Write a main() function to exercise these functions.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool calc_elements(vector<int> &vec, int pos);
void display_elems(vector<int> &vec,
					const string &title, ostream &os=cout);

int main()
{
	vector<int> pent;
	const string title("Pentagonal Numeric Series");

	if (calc_elements(pent, 0))
		display_elems(pent, title);

	if (calc_elements(pent, 8))
		display_elems(pent, title);

	if (calc_elements(pent, 14))
		display_elems(pent, title);

	if (calc_elements(pent, 138))
		display_elems(pent, title);

	return 0;
}

bool calc_elements(vector<int> &vec, int pos)
{
	if (pos <= 0 || pos > 64) {
		cerr << "Sorry. Invalid position: " << pos << endl;
		return false;
	}

	for (int ix = vec.size()+1; ix <= pos; ++ix)
		vec.push_back((ix*(3*ix-1))/2);

	return true;
}

void display_elems(vector<int> &vec,
					const string &title, ostream &os)
{
	os << '\n' << title << "\n\t";
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}
