// 3.8.cpp : Using a Set
#include <set>
#include <string>
set<string> word_exclusion;

while (cin >> tword)
{
	if (word_exclusion.count(tword))
		// present in the set of excluded words?
		// then skip the rest of this iteration
		continue;

	// ok: if here, not an excluded word
	words[tword]++;
}

int ia[10] = { 1, 3, 5, 8, 5, 3, 1, 5, 8, 1 };

vector<int> vec(ia, ia+10);
set<int> iset(vec.begin(), vec.end());

iset.insert(ival);

iset.insert(vec.begin(), vec.end());

set<int>::iterator it = iset.begin();
for (; it != iset.end(); ++it)
	cout << *it << ' ';
cout << endl;

// generic algorithms:
	// set_intersection();
	// set_union();
	// set_difference();
	// set_symmetic_difference();

