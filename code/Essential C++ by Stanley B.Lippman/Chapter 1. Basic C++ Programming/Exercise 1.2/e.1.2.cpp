// Exercise 1.2: e.1.2.cpp

// Comment out the string header file:
// // #include <string>
// Now recompile the program. What happens? Now restore the string header and comment out
// //using namespace std;
// What happens?

// Exercise 1.1 e.1.1.cpp

// Enter the main() program, shown earlier. Either type it in directly or download the program;
// see the Preface for how to acquire the source programs and solutions to exercises. Compile 
// and execute the program on your system.

#include <iostream>
// #include <string>	// comment out the string header file, not effort?
						// because the iostream header file include the string header file.
using namespace std;	// haven't explained this yet ...

int main()
{
	string user_name;
	cout << "Please enter your first name: ";
	cin >> user_name;
	cout << '\n'
		 << "Hello, "
		 << user_name
		 << " ... and goodbye!\n";

	return 0;
	/* If we don't place an explicit return statement at the end of main(),
	 * a "return 0;" statement is inserted automatically. 
	 * In the program examples in this book, I do not place an explicit statement.
	 */
}

/* Test input in terminal:
 * >> Please enter your first name: anna
 * >> 
 * >> Hello, anna ... and goodbye!
 */
