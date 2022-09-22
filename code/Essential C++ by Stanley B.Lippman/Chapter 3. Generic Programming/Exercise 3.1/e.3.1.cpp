/* Exercise 3.1: e.3.1.cpp */

/*
Write a program to read a text file. Store each word in a map. The key value of the map is the
count of the number of times the word appears in the text. Define a word exclusion set containing
words such as a, an, or, the, and, and but. Before entering a word in the map, make sure it is not
present in the word exclusion set. Display the list of words and their associated count when the 
reading of text is complete. As an extension, before displaying the text, allow the user to query
the text for the presence of a word.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

int main()
{
	const std::string sa[] = { "a", "an", "or", "the", "and", "but" };
	std::vector<std::string> svec(sa,sa+6);
	std::set<std::string> word_exclusion(svec.begin(), svec.end());
	std::string tword;
	std::map<std::string,int> words;

	std::cout << "enter \"exit()\" to stop input\n";
	while( std::cin >> tword && tword != "exit()")
	{
		if (word_exclusion.count(tword))
			// present in the set of excluded words?
			// then skip the rest of this iteration
			continue;

		// ok: if here, not an excluded word
		words[tword]++;
	}

	std::string search_word;
	std::cout << "please enter a word you want to query:\n";
	std::cin >> search_word;
	if(words.count(search_word))
		std::cout << search_word << ": " << words[search_word] << '\n';
	else
		std::cout << "Not find " << search_word << '\n';

	std::map<std::string,int>::iterator it = words.begin();
	for(; it != words.end(); ++it)
		std::cout << "key: " << it->first
				<< " value: " << it->second << std::endl;
}
