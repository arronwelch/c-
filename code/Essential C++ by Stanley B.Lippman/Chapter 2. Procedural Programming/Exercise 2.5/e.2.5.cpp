/* Exercise 2.5: e.2.5.cpp */

/*
Implement an overloaded set of max() function to accept (a) two integers,(b) two floats,(c)
two strings,(d) a vector of integers,(e) a vector of floats,(f) a vector of strings,(g) an 
array of integers and an integer indicating the size of the array,(h) an array of floats and 
an integer indicating the size of the array, and (i) an array of strings and an integer
indicating the size of the array. Again, write a main() function to exercise these functions.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline int mymax(int t1, int t2)
{ return t1 > t2 ? t1 : t2; }

inline float mymax(float t1, float t2)
{ return t1 > t2 ? t1 : t2; }

inline string mymax(const string& t1, const string& t2)
{ return t1 > t2 ? t1 : t2; }

inline int mymax(const vector<int> &vec)
{ return *max_element(vec.begin(), vec.end()); }

inline float mymax(const vector<float> &vec)
{ return *max_element(vec.begin(), vec.end()); }

inline string mymax(const vector<string> &vec)
{ return *max_element(vec.begin(), vec.end()); }

inline int mymax(const int *parray, int size)
{ return *max_element(parray, parray+size); }

inline float mymax(const float *parray, int size)
{ return *max_element(parray, parray+size); }

inline string mymax(const string *parray, int size)
{ return *max_element(parray, parray+size); }

int main()
{
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
