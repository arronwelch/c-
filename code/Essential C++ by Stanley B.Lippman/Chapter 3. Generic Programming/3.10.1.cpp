// 3.10.1.cpp : Using the iostream Iterators

#include <iostream>		// std::cout, std::cin
#include <string>		// std::string
#include <vector>		// std::vector
#include <algorithm>	// std::sort()

//using namespace std;

int main()
{
	std::string word;
	std::vector<std::string> text;

	std::cout << "you can enter \"done()\" to stop input!\n";
	// ok: let's read each word in turn until done
	while ( std::cin >> word && word != "done()")
		text.push_back(word);

	// ok: sort it
	std::sort(text.begin(), text.end());

	// ok: let's write them back
	for (int ix = 0; ix < text.size(); ++ix)
		std::cout << text[ix] << ' ';
	std::cout << '\n';
}
