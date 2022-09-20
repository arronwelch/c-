// 3.7.1.cpp : Using a Map

#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string,int> words;

	words["vermeer"] = 1;

	std::string tword;
	while (std::cin >> tword && tword != "exit()")
		words[tword]++;

	std::map<std::string,int>::iterator it = words.begin();
	for (; it != words.end(); ++it)
		std::cout << "key: " << it->first
			 << " value: " << it->second << std::endl;

	int count = 0;
	if (!(count = words["vermeer"]))
		// vermeer not present
		;
	std::cout << "first way:\t\ncount = " << count << std::endl;
	
//	words.find("vermeer");
	
//	int count = 0;
	count = 0;
//	map<string,int>::iterator it;
//	it = 0;
	it = words.find("vermeer");
	if (it != words.end())
		count = it->second;
	std::cout << "second way:\t\ncount = " << count << std::endl;
	
//	int count = 0;
	count = 0;
	std::string search_word("vermeer");
	
	if (words.count(search_word)) // ok, present ...
		count = words[search_word];

	std::cout << "third way:\t\ncount = " << count << std::endl;
	return 0;
}