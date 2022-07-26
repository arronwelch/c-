#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	// seq_data.txt is opened in output mode
	// ofstream outfile("seq_data.txt");

	string usr_name = "Anna";
	int num_tries = 1024;
	int num_right = 2048;

	// seq_data.txt is opened in append mode
	// new data is added at the end of the file
	ofstream outfile("seq_data.txt", ios_base::app);

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

	// manipulator: endl,hex,oct,setprecision(n)
	cout << "dec : " << dec << num_tries << endl;
	cout << "hex : " << hex << num_tries << endl;
	cout << "oct : " << oct << num_tries << endl;

	// infile opened in output mode
	ifstream infile("seq_data.txt");
	/* int */ num_tries = 0;
	int num_cor = 0;

	if(! infile)
	{
		// open failed for some reason ...
		// we'll presume it it a new user ...
		cout << "open failed for some reason ...\n";
		cout << "we'll presume it it a new user ...\n";
	}
	else
	{
		// ok: read each line of the input file
		//		set if user has played before ...
		// format of each line:
		//		name num_tries num_correct
		// nt:	number of tries
		// nc:	number of correct guesses

		string name;
		int nt;
		int nc;

		while (infile >> name)
		{
			infile >> nt >> nc;
			if (name == usr_name)
			{
				// match!
				cout << dec;
				cout << "Welcome back, " << usr_name
					 << "\nYour current score is " << nc
					 << " out of " << nt << "\nGood Luck!\n";

				num_tries = nt;
				num_cor = nc;
			}
		}
	}

	fstream iofile("seq_data.txt",
						ios_base::in|ios_base::app);

	if (! iofile)
		// open failed for some reason .. darn!
		cout << "open failed for some reason .. darn!";
	else
	{
		// reposition to front of file to begin reading
		iofile.seekg(0);

		// ok: everything else is the same ...
	}

	return 0;
}
