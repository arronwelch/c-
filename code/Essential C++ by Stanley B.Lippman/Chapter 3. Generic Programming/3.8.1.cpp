// 3.8.1.cpp

#include <iostream>
#include <vector>
#include <set>
#include <iterator>

int main()
{
	int ia[10] = { 1, 3, 5, 8, 5, 3, 1, 5, 8, 1 };
	std::vector<int> ivec(ia, ia+10);
	std::set<int> iset(ivec.begin(), ivec.end());

	std::set<int>::iterator it = iset.begin();
	for( ; it != iset.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}
