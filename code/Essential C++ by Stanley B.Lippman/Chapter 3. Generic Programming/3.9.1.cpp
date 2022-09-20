// 3.9.1.cpp : How to Use Iterator Inserters

#include <iostream>		// std::cout, std::endl;
#include <vector>		// std::vector
#include <binders.h>	// std::bind2nd()
#include <functional>	// std::find_if(), std::less()
#include <iterator>		// std::back_inserter()

template <typename InputIterator, typename OutputIterator,
		typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
		OutputIterator at, const ElemType &val, Comp pred)
{
	while ((first =
			std::find_if(first, last,
			std::bind2nd(pred,val))) != last)
	{
		// just to see what is going on ...
		std::cout << "found value: " << *first << std::endl;

		// assign value, then advance both iterators
		*at++ = *first++;
	}
	return at;
}

int main()
{
	const int elem_size = 8;

	int ia[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
	std::vector<int> ivec(ia, ia+elem_size);

	// built-in arrays do not support insertion ...
	int ia2[elem_size];
	std::vector<int> ivec2;

	std::cout << "filtering integer array for values less than 8\n";
	filter(ia, ia+elem_size, ia2,
			elem_size, std::less<int>());

	std::cout << "filtering integer vector for values greater than 8\n";
	filter(ivec.begin(), ivec.end(),
			std::back_inserter(ivec2),
			elem_size, std::less<int>());
}
