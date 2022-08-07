/* Exercise 2.6: e.2.6.cpp */

/*
Reimplement the function of Exercise 2.5 using templates. Modify the main() function
accordingly.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename Type>
inline Type mymax(Type t1, Type t2) { return t1 > t2 ? t1 : t2; }

template <typename elemType>
inline elemType mymax(const vector<elemType> &vec)
	{ return *max_element(vec.begin(), vec.end()); }

template <typename arrayType>
inline arrayType mymax(const arrayType *parray, int size)
	{ return *max_element(parray, parray+size); }

// note: no changes required to main()!
int main() {
	// same as in exercise 2.4
	string sarray[] = { "we", "were", "her", "pride", "of", "ten" };
	vector<string> svec(sarray, sarray+6);

	int iarray[] = { 12, 70, 2, 169, 1, 5, 29 };
	vector<int> ivec(iarray, iarray+7);

	float farray[] = { 2.5, 24.8, 18.7, 4.1, 23.9 };
	vector<float> fvec(farray, farray+5);

	int imymax = mymax(mymax(ivec), mymax(iarray, 7));
	float fmymax = mymax(mymax(fvec), mymax(farray, 5));
	string smymax = mymax(mymax(svec), mymax(sarray, 6));

	cout << "imymax should be 169  -- found: " << imymax << endl;
	cout << "fmymax should be 24.8 -- found: " << fmymax << endl;
	cout << "smymax should be were -- found: " << smymax << endl;

	return 0;
}
