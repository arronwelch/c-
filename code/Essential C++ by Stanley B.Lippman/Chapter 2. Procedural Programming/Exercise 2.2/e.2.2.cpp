// Exercise 2.2

/*
 * The formula for the Pentagonal numeric sequence is Pn=n*(3n-1)/2. This yields the sequence
 * 1, 5, 12, 22, 35, and so on. Define a function to fill a vector of elements passed in to the
 * function calculated to some user-specified position. Be sure to verify that the position
 * specified is valid. Write a second function the type of numeric series the vector represents.
 * Write a main() function to exercise these functions.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int>* pent_seq(int pos)
{
	const int max_size = 1024;
	static vector<int> vec;
	if (pos <= 0 || pos > max_size)
	{
		cout << "Oops: invalid position![pent_seq]" << endl;
		return 0;
	}

	for (int ix=vec.size(); ix < pos; ++ix)
		vec.push_back((ix+1)*(3*(ix+1)-1)/2);

	return &vec;
}

bool pent_elem(int pos, int &elem)
{
	vector<int>* seq_ptr = pent_seq(pos);
	const int max_size = 1024;
	if (pos <= 0 || pos > 1024)
	{
		cerr << "Oops: invalid position![pent_elem]" << endl;
		return false;
	}

	elem = (*seq_ptr)[pos-1];
	return true;
}

void display_vector(vector<int>& vec)
{
	for (int ix = 0; ix < vec.size(); ++ix)
		cout << vec[ix] << ' ';
	cout << endl;
}

int main(void)
{
	const int pos = 5;
	int elem = 0;
	display_vector(*pent_seq(pos));
	cout << pent_elem(pos, elem) << endl;
	cout << elem << endl;

	return 0;
}
