// Exercise 1.2 a.cpp

// Comment out the string header file:
// // #include <string>
// Now recompile the program. What happens? Now restore the string header and comment out
// //using namespace std;
// What happens?
// Exercise 1.1 a.cpp

// Enter the main() program, shown earlier. Either type it in directly or download the program;
// see the Preface for how to acquire the source programs and solutions to exercises. Compile 
// and execute the program on your system.

// Exercise 1.1 a.cpp

// Enter the main() program, shown earlier. Either type it in directly or download the program;
// see the Preface for how to acquire the source programs and solutions to exercises. Compile 
// and execute the program on your system.

#include <iostream>
//#include <string>
//using namespace std;	// haven't explained this yet ...
int main()
{
	cout << "Please enter your first name: ";
	string user_name;
	cin >> user_name;
//	cout << '\n';
//	cout << "Hello, ";
//	cout << user_name;
//	cout << " ... and goodbye!\n";
//
//	cout << "3 + 4 = ";
//	cout << 3 + 4;
//	cout << '\n';
//	// our program code goes here

	cout << '\n'
		 << "Hello, "
		 << user_name
		 << " ... and goodbye!\n";

	return 0;
/*
If we don't place an explicit return statement at the end of main(), a return 0; statement is
inserted automatically. In the program examples in this book, I do not place an explicit
statement.
 */
}

/*

Please enter your first name: anna
Hello, anna ... and goodbye!
3 + 4 = 7
 */

