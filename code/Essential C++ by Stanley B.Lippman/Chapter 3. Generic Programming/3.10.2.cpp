// 3.10.2.cpp : istream_iterator and ostream_iterator

#include <iostream>		// std::cout
#include <iterator>		// std::istream_iterator, std::ostream_iterator, std::back_inserter()
#include <algorithm>	// std::sort(), std::copy()
#include <vector>		// std::vector
#include <string>		// std::string

int main()
{
	std::istream_iterator<std::string> is(std::cin);
	std::istream_iterator<std::string> eof;

	std::vector<std::string> text;
	std::copy(is, eof, std::back_inserter(text));

	std::sort(text.begin(), text.end());

	std::ostream_iterator<std::string> os(std::cout, " ");
	std::copy(text.begin(), text.end(), os);
}
