// 3.10.3.cpp : ifstream class objects and ofstream class objects

#include <iostream>		// std::cout
#include <fstream>		// std::ifstream, std::ofstream
#include <iterator>		// std::istream_iterator, std::ostream_iterator
#include <algorithm>	// std::copy()
#include <vector>		// std::vector
#include <string>		// std::string

int main()
{
	std::ifstream in_file("as_you_like_it.txt");
	std::ofstream out_file("as_you_like_it_sorted.txt");

	if (! in_file || ! out_file)
	{
		std::cerr << "!!unable to open the necessary files.\n";
		return -1;
	}

	std::istream_iterator<std::string> is(in_file);
	std::istream_iterator<std::string> eof;

	std::vector<std::string> text;
	std::copy(is, eof, std::back_inserter(text));

	std::sort(text.begin(), text.end());

	std::ostream_iterator<std::string> os(out_file, " ");
	std::copy(text.begin(), text.end(), os);
	out_file << '\n';
}
