// 3.4 Using the Sequential Containers

#include <vector>
#include <list>
#include <deque>

	// 1. Create an empty container:
	list<string> slist;
	vector<int> ivec;

	// 2. Create a container of some size.
	list<int> ilist(1024);
	vector<string> svec(32);

	// 3. Create a container of a given size and specify an initial value for each element:
	vector<int> ivec(10, -1);
	list<string> slist(16, "unassigned");

	// 4. Create a container,providing an iterator pair marking a range of elements with which 
	// to initialize the container:
	int ia[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };
	vector<int> fib(ia, ia+8);

	// 5. Create a container, providing a second container object.
	// The new container is initialized by copying the second.
	list<string> slist;	// empty
	// fill slist ...
	list<string> slist2(slist);	// copy of slist ...

#include <deque>
deque<int> a_line;
int ival;
while (cin >> ival)
{
	// insert ival at back of a_line
	a_line.push_back(ival);

	// ok: read the value at front of a_line
	int curr_value = a_line.front();

	// ... do something ...

	// delete the value of front of a_line
	a_line.pop_front();
}

list<int> ilist;
// ... fill up ilist

list<int>::iterator it = ilist.begin();
while (it != ilist.end())
	if (*it >= ival)
	{
		ilist.insert(it, ival);
		break;	// exit loop
	}

if (it == ilist.end())
	ilist.push_back(ival);

string sval("Part Two");
list<string> slist;
// ... fill slist ...

list<string>::iterator it = find(slist.begin(), slist.end(), sval);
slist.insert(it, 8, string("dummy"));

int ia1[7] = { 1, 1, 2, 3, 5, 55, 89 };
int ia2[4] = { 8, 13, 21, 34 };
list<int> elems(ia1, ia1+7);

list<int>::iterator
	it = find(elems.begin(), elems.end(), 55);

elems.insert(it, ia2, ia2+4);

list<string>::iterator
	it = find(slist.begin(), slist.end(), str);
slist.erase(it);

list<string>::iterator
	first = slist.begin(),
	last = slist.end();

// it1 : first element to erase
// it2 : first element beyond elements to erase
list<string>::iterator it1 = find(first, last, str);
list<string>::iterator it2 = find(first, last, sval);

slist.erase(it1, it2);

// error: offset arithmetic is not
// supported for list class
slist.erase(it1, it1+num_tries);

