// 4.9.cpp: Implementing a Function Object

#include <iostream>

using std::cout;

class LessThan {
public:
	LessThan(int val) : _val(val) {}
	int comp_val() const { return _val; }
	void comp_val(int nval) { _val = _nval; }

	bool operator() (int value) const;

private:
	int _val;
};

inline bool operator() (int value) const { return value < _val; }

int main()
{
	LessThan lt10(10);

	cout << "Hello, Function Object!\n";
}
