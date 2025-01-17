// 4.9.cpp: Implementing a Function Object

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::endl;
using std::ostream;

class LessThan {
public:
	LessThan(int val) : _val(val) {}
	int comp_val() const { return _val; }
	void comp_val(int nval) { _val = nval; }

	bool operator() (int value) const;

private:
	int _val;
};

inline bool LessThan::
operator() (int value) const { return value < _val; }

int count_less_than(const vector<int> &vec, int comp)
{
	LessThan lt(comp);

	int count = 0;
	for (int ix = 0; ix < vec.size(); ++ix)
		if (lt(vec[ix]))
			++count;

	return count;
}

void print_less_than(const vector<int> &vec,
					int comp, ostream &os = cout)
{
	LessThan lt(comp);
	vector<int>::const_iterator iter = vec.begin();
	vector<int>::const_iterator it_end = vec.end();

	os << "elements less than " << lt.comp_val() << endl;
	while ((iter = find_if(iter, it_end, lt)) != it_end)
	{
		os << *iter << ' ';
		++iter;
	}
	os << '\n';
}

int main()
{
	cout << "Hello, Function Object!\n";

	int ia[16] = { 17, 12, 44,  9, 18, 45,  6, 14,
				   23, 67,  9,  0, 27, 55,  8, 16 };
	vector<int> vec(ia, ia+16);
	int comp_val = 20;

	cout << "Number of elements less than "
		 << comp_val << " are "
		 << count_less_than(vec, comp_val) << endl;
	print_less_than(vec, comp_val);

}
