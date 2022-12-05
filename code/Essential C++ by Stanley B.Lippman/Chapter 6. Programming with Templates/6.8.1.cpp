/* 6.8 Member Template Functions */

#include <iostream>
#include <string>

using namespace std;

class PrintIt {
public:
	PrintIt(ostream &os)
		: _os(os) {}

	// a member template function
	template <typename elemType>
	void print(const elemType &elem, char delimiter = '\n')
		{ _os << elem << delimiter; }
private:
	ostream& _os;
};

int main()
{
	cout << "Hello! 6.8 Member Template Functions\n";
	PrintIt to_standard_out(cout);
	to_standard_out.print("hello");
	to_standard_out.print(1024);

	string my_string("i am a string");
	to_standard_out.print(my_string);
}

