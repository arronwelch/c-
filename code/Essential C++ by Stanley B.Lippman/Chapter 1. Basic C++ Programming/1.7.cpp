#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	// seq_data.txt is opened in output mode
	ofstream outfile("seq_data.txt");

	string usr_name = "Anna";
	int num_tries = 1024;
	int num_right = 2048;

	// seq_data.txt is opened in append mode
	// new data is added at the end of the file
	ofstream outfile1("seq_data.txt", ios_base::app);

	// if outfile evaluates as false,
	// the file could not be opened
	if (! outfile)
		// open failed for some reason ...
		cout << "Oops! Unable to save session data!\n";
	else
		// ok: outfile is open, let's write the data
		outfile << usr_name << ' '
				<< num_tries << ' '
				<< num_right << endl;

}
