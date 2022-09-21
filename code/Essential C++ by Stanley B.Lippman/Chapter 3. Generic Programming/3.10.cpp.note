// 3.10.cpp : Using the iostream Iterators

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string word;
	vector<string> text;

	// ok: let's read each word in turn until done
	while ( cin >> word )
		text.push_back(word);

	// ok: sort it
	sort(text.begin(), text.end());

	// ok: let's write them back
	for (int ix = 0; ix < text.size(); ++ix)
		cout << text[ix] << ' ';
}
