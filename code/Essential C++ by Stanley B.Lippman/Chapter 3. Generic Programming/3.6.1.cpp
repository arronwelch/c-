// 3.6.1.cpp

#include <iostream>		// std::cout, std::endl;
#include <vector>		// std::vector
#include <functional>	// std::bind2nd() std::less<int>()
#include <algorithm>	// std::find_if()

template <typename InputIterator, typename OutputIterator,
			typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last,
		OutputIterator at, const ElemType &val, Comp pred)
{
	while ((first = 
				std::find_if(first, last,
				std::bind2nd(pred, val))) != last)
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

	// containers to hold the results of our filter()
	int ia2[elem_size];
	std::vector<int> ivec2(elem_size);

	std::cout << "filtering tnteger array for values less than 8\n";
	filter(ia, ia+elem_size, ia2, elem_size, std::less<int>());

	std::cout << "filtering integer vector for values greater than 8\n";
	filter(ivec.begin(), ivec.end(), ivec2.begin(),
			elem_size, std::greater<int>());
}

