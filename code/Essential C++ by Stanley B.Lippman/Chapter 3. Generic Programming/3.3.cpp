// 3.3 Operations Common to All Containers

#include <iostream>
#include <vector>

using namespace std;

// 1. The equality(==) and inequality(!=) operators return true of false.
// 2. The assignment(=) operator copies one container into another.
// 3. empty() returns true if the container holds no elements.
// 4. size() returns a count of the elements currently held within the container.
// 5. clear() deletes all the elements.

void comp(vector<int> &v1, vector<int> &v2)
{
	// are the two vectors equal?
	if (v1 == v2)
		return;

	// is either vector empty?
	if (v1.empty() || v2.empty()) return;

	// no point defining it unless we are going to use it!
	vector<int> t;

	// assign t the largest vector
	t = v1.size() > v2.size() ? v1 : v2;

	// ... use t ...

	// ok. empty t of its elements
	// t.empty() will now return true
	// t.size() wil now return 0
	t.clear();

	// ... ok, fill up t and use it some more ...
}

// 1. begin() returns an iterator to the first element
// 2. end() returns an iterator that addresses 1 past the last element.

// 3. insert() adds one or a range of elements to a container.
// 4. erase() deletes one or a range of elements from a container.

int main(void)
{
	const int ia1[5] = { 3, 6, 1, 9, 7 };
	const int ia2[2] = { 1, 10 };

	vector<int> ivec1(ia1,ia1+5),ivec2(ia2,ia2+2);
	if ( ivec1 == ivec2 )
		cout << "ivec1 is equal to ivec2" << endl;
	else
		cout << "ivec1 is not equal to ivec2" << endl;

	if ( ivec1.empty() )
		cout << "ivec1 is empty" << endl;
	else
		cout << "ivec1 is not empty" << endl;

	vector<int> t;
	t = ivec1.size() > ivec2.size() ? ivec1 : ivec2;
	cout << "t.size() = " << t.size() << endl;
	for(int ix = 0; ix < t.size(); ++ix)
		cout << t[ix] << ' ';
	cout << endl;

	t.clear();
	cout << "t.size() = " << t.size() << endl;
	for(int ix = 0; ix < t.size(); ++ix)
		cout << t[ix] << ' ';
	cout << endl;

	vector<int>::iterator iter;
	cout << "ivec2.size() = " << ivec2.size() << endl;
	for(iter = ivec2.begin(); iter < ivec2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	ivec2.insert(ivec2.begin(), 5);
	cout << "ivec2.size() = " << ivec2.size() << endl;
	for(iter = ivec2.begin(); iter < ivec2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	ivec2.erase(ivec2.begin()+1);
	cout << "ivec2.size() = " << ivec2.size() << endl;
	for(iter = ivec2.begin(); iter < ivec2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}
