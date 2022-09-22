/* Exercise 3.1: e.3.1.cpp */

/*
Write a program to read a text file. Store each word in a map. The key value of the map is the
count of the number of times the word appears in the text. Define a word exclusion set containing
words such as a, an, or, the, and, and but. Before entering a word in the map, make sure it is not
present in the word exclusion set. Display the list of words and their associated count when the 
reading of text is complete. As an extension, before displaying the text, allow the user to query
the text for the presence of a word.
*/

#include <iostream>		// std::cout, std::endl
#include <fstream>		// std::ifstream, std::ofstream
#include <string>
#include <set>
#include <map>

void InitExclusionSet(std::set<std::string> &sset)
{
	std::string exclusionWord[] = { "a", "an", "or", "the", "and", "but" };
	sset.insert(exclusionWord,exclusionWord+6);
}

void ProcessFile(std::map<std::string,int> &simap, std::set<std::string> &sset, std::ifstream &ifile)
{
	std::string word;
	while (ifile >> word)
	{
		if (sset.count(word))
			continue;
		simap[word]++;
	}
}

void UserQuery(std::map<std::string,int> &simap, std::set<std::string> &sset)
{
	std::string queryWord;
	std::cout << "Please enter the word you want to query: ";
	std::cin >> queryWord;

	std::map<std::string,int>::iterator iter;
	iter = simap.find(queryWord);
	if( iter != simap.end())
	{
		std::cout << "The word \"" << queryWord << "\" has appeared " << simap[queryWord] 
		<< " times." << std::endl;
	}
	else if (sset.count(queryWord))
		std::cout << "Sorry, the word \"" << queryWord << "\" is the excluded word.\n";
	else
		std::cout << "Sorry, the word \"" << queryWord << "\" is not found." << std::endl;

}

void DisplayWordCount(std::map<std::string,int> &simap, std::ofstream &ofile)
{
	for (std::map<std::string,int>::iterator itr = simap.begin(), mapEnd = simap.end();
			itr != mapEnd; ++itr)
	{
		ofile << "key: " << itr->first
				<< " value: " << itr->second << '\n';
	}
}

int main(int argc, char *argv[])
{
	std::ifstream readFile("TestFile_3.1.txt");
	std::ofstream writeFile("TestFile_3.1.map");

	if (!readFile.is_open() || !writeFile.is_open()) {
		std::cerr << "Sorry, the file fails to read!" << std::endl;
		return -1;
	}

	std::map<std::string,int> mapWord;
	std::set<std::string> setExclusion;

	InitExclusionSet(setExclusion);
	ProcessFile(mapWord, setExclusion, readFile);
	UserQuery(mapWord, setExclusion);
	DisplayWordCount(mapWord, writeFile);

	return 0;
}
