// 1.4 Writing Conditional and Loop Statements

// Pseudo code: General logic of our program
/*
while the user wants to guess a sequence
{ #1
	display the sequence
	while the guess is not correct and
		  the user wants to guess again
	{ #2
		read guess
		increment number-of-tries count
		if the guess is correct
		{ #3
			increment correct-guess count
			set got_it to true
		} else {
			express regret that the user has guessed wrong
				generate a different response based on the
				current number of guesses by the user // #4
			ask the user if she wants to guess again
			read response
			if user says no // #5
			set go_for_it to false
		}
	}
}

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	char usr_rsp;
	bool go_for_it = true;
	bool got_it = false;
	int usr_guess;
	int next_elem;
	int num_tries = 0;
	int num_right = 0;
	int num_cor = 0;
	const int seq_size = 18;

    int elem_val[seq_size] = {
        1, 2,  3, 3, 4,  7, 2,  5, 12,
        3, 6, 10, 4, 9, 16, 5, 12, 22
    };
    vector<int> elem_seq(elem_val, elem_val + seq_size);

	// #5
    cout << "Want to try another sequence? (Y/N)\n";
    cin >> usr_rsp;
	if (usr_rsp == 'N' || usr_rsp == 'n')
		go_for_it = false;

	// #3
    int cur_tuple = 0;

        cout << "The first two elements of the sequence are: "
             << elem_seq[cur_tuple] << ", "
             << elem_seq[cur_tuple + 1]
             << "\nWhat is the next element? ";
        // ...
        cin >> usr_guess;

	next_elem = elem_seq[cur_tuple + 2];
	if (usr_guess == next_elem)
	{	// begins statement block
		num_right++;
		got_it = true;
		cout << "correct!\n";
	}	// ends statement block

	// oops: the statement block is missing
	// only num_cor++ is part of if statement
	// got_it = true; is executed unconditionally
	if (usr_guess == next_elem)
		num_cor++;
		got_it = true;

	// The if statement also supports an else clause.
	if (usr_guess == next_elem)
	{
		// user guessed correctly
		;
	}
	else
	{
		// user guessed incorrectly
		;
	}

	// A second use fo the else clause is to string together two or more if statements.
	if (num_tries == 1)
		cout << "Oops! Nice guess but not quite it.\n";
	if (num_tries == 2)
		cout << "Hmm. Sorry. Wrong a second time.\n";
	if (num_tries == 3)
		cout << "Ah, this is harder than it looks, isn't is?\n";

	// However, only one of the three conditions can be true at any one time.

	if (num_tries == 1)
		cout << "Oops! Nice guess but not quite it.\n";
	else
	if (num_tries == 2)
		cout << "Hmm. Sorry. Wrong a second time.\n";
	else
	if (num_tries == 3)
		cout << "Ah, this is harder than it looks, isn't is?\n";
	else
		cout << "It must be getting pretty frustrating by now!\n";

	// One confusing aspect of nested if-else clauses is the difficulty of organizing their 
	// logic correctly.
	if (usr_guess == next_elem)
	{
		// user guessed correctly
		;
	}
	else
	if (num_tries == 1)
		// ... output response
		;
	else
	if (num_tries == 2)
		// ... output response
		;
	else
	if (num_tries == 3)
		// ... output response
		;
	else
		// ... output response
		;

	// now ask user if she wants to guess again
	// but only if she has guessed wrong
	// oops! where can we place it?

	// Each else-if clause has unintentionally been made an alternative to guessing the value
	// correctly.As a result, we have no place to put the second part of our code to handle
	// the user having guessed incorrectly.
	// Here is the correct organization:
	if (usr_guess == next_elem)
	{
		// user guessed correctly
	}
	else
	{
		// user guessed incorrectly
		if (num_tries == 1)
			// ...
			;
		else
		if (num_tries == 2)
			// ...
			;
		else
		if (num_tries == 3)
			// ...
			;
		else
			// ...
			;

		cout << "Want to try again? (Y/N) ";
		char usr_rsp;
		cin >> usr_rsp;

		if (usr_rsp == 'N' || usr_rsp == 'n')
			go_for_it = false;
	}

	// If the value of the condition being tested is an integral type, we can replace the 
	// if-else-if set of clauses with a switch statement:

	// equivalent to if-else-if clauses above
	switch (num_tries)
	{
		case 1:
			cout << "Oops! Nice guess but not quite it.\n";
			break;
		case 2:
			cout << "Hmm. Sorry. Wrong again.\n";
			break;
		case 3:
			cout << "Ah, this is harder than it looks, isn't it?\n";
			break;
		default:
			cout << "It must be getting pretty frustrating by now!\n";
			break;
	}

	// If num_tries equals 2,for example, and if there was no break statement,the output would
	// look like this:

	// output if num_tries == 2 and
	//		we had forgotten the break statements
	/*
	Hmm. Sorroy. Wrong again.
	Ah, this is harder than it looks, isn't it?
	It must be getting pretty frustrating by now!
	*/

	// Why, you're probably asking, is the switch statement designed this way?
	// Here is an example of this fall-through behavior being just right:

	char next_char = 'a';
	int vowel_cnt = 0;

	switch( next_char )
	{
		case 'a': case 'A':
		case 'e': case 'E':
		case 'i': case 'I':
		case 'o': case 'O':
		case 'u': case 'U':
			++vowel_cnt;
			break;
	// ...
	}
	cout << "vowel_cnt = " << vowel_cnt << endl;

	// Loop Statements

	/*
	while the user wants to guess a sequence
	{
		display the sequence
		while the guess is not correct and
			  the user wants to guess again
	}
	*/

	// The C++ while loop maps nicely to our needs:

	bool next_seq = true;		// show next sequence ?
	// bool go_for_it = true;		// user wanst to guess ?
	// bool got_it = false;		// user guessed correctly ?
	// int num_tries = 0;			// number of user guesses
	// int num_cor = 0;			// number of correct answers

	while (next_seq == true)
	{
		// display sequence to user
		while ((got_it == false) &&
			   (go_for_it == true))
		{
			int usr_guess;
			cin >> usr_guess;
			num_tries++;

			if (usr_guess == next_elem)
			{
				got_it = true;
				num_cor++;
			}
			else
			{	// user guessed incorrectly
				// tell user answer is wrong
				// ask user if she wants to try again
				if (usr_rsp == 'N' || usr_rsp == 'n')
					go_for_it = false;
			}	
		}	// end of nested while loop

		cout << "Want to try another sequence? (Y/N) ";
		char try_again;
		cin >> try_again;

		if (try_again == 'N' || try_again == 'n')
			next_seq = false;
	}	// end of while(next_seq == true)

	// A loop can be terminated within the body of its code sequence by the execution of a
	// break statement.

	int max_tries = 3;
	int tries_cnt = 0;
	while (tries_cnt < max_tries)
	{
		// read user guess
		if (usr_guess == next_elem)
			break;	// terminate loop

		tries_cnt++;
		// more stuff
	}

	// The program can short-circuit execution of the current iteration of the loop by executing
	// a continue statement.

	void process_text(string);
	string word;
	const int min_size = 4;
	while (cin >> word)
	{
		if (word.size() < min_size)
			// terminates this iteration
			continue;
		// reach here only if the word is
		// greater than or equal min_size ...
		process_text(word);
	}
	// The continue statement causes the current loop iteration to terminate.
}

void process_text(string word)
{
	cout << "string is " << word << endl;
}