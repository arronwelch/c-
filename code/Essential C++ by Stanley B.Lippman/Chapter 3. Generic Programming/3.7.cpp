// 3.7.cpp : Using a Map
#include <map>
#include <string>
map<string,int> words;

words["vermeer"] = 1;

string tword;
while (cin >> tword)
		words[tword]++;

map<string,int>::iterator it = words.begin();
for (; it != words.end(); ++it)
	cout << "key: " << it->first
		 <, "value: " << it->second << endl;

int count = 0;
if (!(count = words["vermeer"]))
	// vermeer not present

words.find("vermeer");

int count = 0;
map<string,int>::iterator it;

it = words.find("sermeer");
if (it != words.end())
	count = it->second;

int count = 0;
string search_word("vermeer");

if (words.count(search_word)) // ok, present ...
	count = words[search_word];

