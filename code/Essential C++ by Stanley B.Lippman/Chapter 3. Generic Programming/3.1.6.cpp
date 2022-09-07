// 3.1.6.cpp

#include <iostream>
#include <string>

using namespace std;

template <typename elemType>
const elemType* my_find(const elemType* first,
						const elemType* last,
						const elemType &value)
{
	if (!first || !last)
		return 0;

	for(; first!=last; ++first)
		if( *first == value)
			return first;

	return 0;
}
int main(void)
{
	int ia[8] = { 1, 1, 2, 3, 5, 8, 13, 21 };
	double da[6] = { 1.5, 2.0, 2.5, 3.1, 3.5, 4.0 };
	string sa[4] = { "pooh", "piglet", "eeyore", "tigger" };

	const int		*pi = my_find(ia, ia+8, ia[3]);
	const double 	*pd = my_find(da, da+6, da[3]);
	const string	*ps = my_find(sa, sa+4, sa[3]);

	cout << *pi << endl;
	cout << *pd << endl;
	cout << *ps << endl;

	return 0;
}