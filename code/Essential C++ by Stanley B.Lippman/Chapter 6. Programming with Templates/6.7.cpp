/* 6.7 Template Parameters as Strategy */

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

template <typename elemType>
class LessThan {
public:
	LessThan(const elemType &val) : _val(val) {}
	bool operator() (const elemType &val) const
		{ return val < _val; }

	void val(const elemType &newval) { _val = newval; }
	elemType val() const { return _val; }
private:
	elemType _val;
};

LessThan<int> lti1024(1024);
LessThan<string> ltsPooh("Pooh");

template <typename elemType, typename Comp = less<elemType> >
class LessThanPred {
public:
	LessThanPred(const elemType &val) : _val(val) {}
	bool operator() (const elemType &val) const
		{ return Comp(val, _val); }

	void val(const elemType &newval) { _val = newval; }
	elemType val() const { return _val; }
private:
	elemType _val;
};

// alternative function object comparison
class StringLen {
public:
	bool operator() (const string &s1, const string &s2)
		{ return s1.size() < s2.size(); }
};

LessThanPred<int> ltpi(1024);
LessThanPred<string, StringLen> ltps("Pooh");

int main()
{
	cout << "Hello! 6.7 Template Parameters as Strategy\n";
	cout << "lti1024(1) => (1 < " << lti1024.val() << ") : " << lti1024(1) << endl;
	cout << "ltsPooh(\"PooH\") => (\"PooH\" < \"" << ltsPooh.val() 
		 << "\") : " << ltsPooh("PooH") << endl;

	cout << ltpi.val() << endl;
	cout << ltps.val() << endl;
}

// template <typename elemType, typename BinaryComp>
// class Compare;
// 
// template <typename num_seq>
// class NumericSequence {
// public:
// 	NumericSequence(int len = 1, int bpos = 1)
// 		: _ns(len, bpos) {}
// 	// this invokes the unknown numeric sequence
// 	// member functions through a naming discipline:
// 	// each num_seq parameter class must provide a
// 	// named function clac_elem(), is_elem(), and so on ...
// 	void calc_elems(int sz) const { _ns.calc_elems(sz); }
// 	bool is_elem(int elem) const { return _ns.is_elem(elem); }
// 
// 	// ...
// private:
// 	num_seq _ns;
// };
