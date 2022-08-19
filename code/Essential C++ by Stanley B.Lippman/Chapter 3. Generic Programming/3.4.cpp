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

