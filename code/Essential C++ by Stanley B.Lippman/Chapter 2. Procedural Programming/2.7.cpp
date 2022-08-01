// 2.7 Defining and Using Template Functions

void display_message(const string&, const vector<int>&);
void display_message(const string&, const vector<double>&);
void display_message(const string&, const vector<string>&);

void display_message(const string&, const vector<string>&,
					 ostream& = cout);
void display_message(const string &msg, const vector<int> &vec)
{
	cout << msg;
	for (int ix = 0; ix <vec.size(); ++ix)
		cout << vec[ix] << ' ';
	cout << '\n';
}

void display_message(const string &msg, const vector<string> &vec)
{
	cout << msg;
	for (int ix = 0; ix <vec.size(); ++ix)
		cout << vec[ix] << ' ';
	cout << '\n';
}

