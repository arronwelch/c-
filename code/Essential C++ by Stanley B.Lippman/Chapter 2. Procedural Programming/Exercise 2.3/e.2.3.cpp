/* Exercise 2.3: e.2.3.cpp */

/*
Separate the function to calculate the Pentagonal numeric sequence implemented in Exercise
2.2 into two functions. One function should be inline; it checks the validity of the position.
A valid position not as yet calculated causes the function to invoke a second function that does
the actual calculation.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool calc_elems(vector<int> &vec, int pos);
void display_elems(vector<int> &vec,
					const string &title, ostream &os=cout);

extern void really_calc_elems(vector<int>&, int);

inline bool calc_elems(vector<int> &vec, int pos)
{
	if (pos <= 0 || pos > 64) {
		cerr << "Sorry. Invalid position: " << pos << endl;
		return false;
	}

	if (vec.size() < pos)
		really_calc_elems(vec, pos);

	return true;
}

void really_calc_elems(vector<int> &vec, int pos)
{
	for (int ix = vec.size()+1; ix <= pos; ++ix)
		vec.push_back((ix*(3*ix-1))/2);
}

int main()
{
	vector<int> pent;
	const string title("Pentagonal Numeric Series");

	if (calc_elems(pent, 0))
		display_elems(pent, title);

	if (calc_elems(pent, 8))
		display_elems(pent, title);

	if (calc_elems(pent, 14))
		display_elems(pent, title);

	if (calc_elems(pent, 138))
		display_elems(pent, title);

	return 0;
}

// bool calc_elems(vector<int> &vec, int pos)
// {
// 	if (pos <= 0 || pos > 64) {
// 		cerr << "Sorry. Invalid position: " << pos << endl;
// 		return false;
// 	}
// 
// 	for (int ix = vec.size()+1; ix <= pos; ++ix)
// 		vec.push_back((ix*(3*ix-1))/2);
// 
// 	return true;
// }

void display_elems(vector<int> &vec,
					const string &title, ostream &os)
{
	os << '\n' << title << "\n\t";
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}
