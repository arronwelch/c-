// 2.7 Defining and Using Template Functions

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// void display_message(const string&, const vector<int>&);
// void display_message(const string&, const vector<double>&);
// void display_message(const string&, const vector<string>&);
// 
// void display_message(const string&, const vector<string>&,
// 					 ostream& = cout);
// 
// void display_message(const string &msg, const vector<int> &vec)
// {
// 	cout << msg;
// 	for (int ix = 0; ix <vec.size(); ++ix)
// 		cout << vec[ix] << ' ';
// 	cout << '\n';
// }
// 
// void display_message(const string &msg, const vector<string> &vec)
// {
// 	cout << msg;
// 	for (int ix = 0; ix <vec.size(); ++ix)
// 		cout << vec[ix] << ' ';
// 	cout << '\n';
// }

template <typename elemType>
void display_message(const string &msg,
					 const vector<elemType> &vec)
{
	cout << msg;
	for (int ix = 0; ix < vec.size(); ++ix)
	{
		// elemType t = vec[ix];
		// cout << t << ' ';
		cout << vec[ix] << ' ';
	}
	cout << endl;
}

// overload instances of a function template
template <typename elemType>
void display_message(const string &msg,
					 const list<elemType> &lt);

int main(void)
{
	const int vec_size = 5;
	const int ia[vec_size] = {1, 3, 5, 7, 9};
	const string sa[vec_size] = { "string1", "string2", "string3", "string4", "string5" };
	vector<int> ivec(ia,ia+vec_size);
	vector<string> svec(sa,sa+vec_size);
	string msg = "test display_message() with template function:\n";

	display_message(msg,ivec);
	display_message(msg,svec);

	return 0;
}
