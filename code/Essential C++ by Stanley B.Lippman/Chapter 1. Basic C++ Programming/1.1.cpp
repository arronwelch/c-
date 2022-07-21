// 1.1 How to Write a C++ Program

// The standard C++ input/output library is called the iostream library.
#include <iostream>

// make the string class known to the program.
// including the string class header file:
#include <string>

// std is the name of the standard library namespace.
// Everything provided within the standard library(such as the string class and
// the iostream class objects cout and cin) is encapsulated within the std namespace.
// A namespace is a method of packaging library names so that they can be introduced
// within a user's program environment without also introducing name clashes.
// (A name clash occurs when there are two entities that have the same name in an 
// application so that the program cannot distinguish between the two.When this happens,
// the program cannot run until the name clash is resolved.)
// Namespaces are a way of fencing in the visibility of names.
using namespace std;

// int is a C++ language keyword.
// Keywords are predefined names given special meaning within the language.
// int represents a built-in integer data type.

// main() is a user-implemented function of the following general form:
int main()
{
	// our program code goes here

	// To write to the user's terminal, we use  a predefined class object named cout
	// (pronouced see out)
	// We direct the data we wish cout to write using the output operator(<<)
	cout << "Please enter your first name: ";

	// This defines user_name as an object of the string class
	// The definition, oddly enough, is called a declaration statement.
	string user_name;

	// To read input from the user's terminal, we use a predefined class object named cin
	// (pronounced see in)
	// We use the input operator(>>) to direct cin to read data from the user's terminal
	// into an object of the appropriate type:
	cin >> user_name;

	cout << "Hello, " << user_name << " ... and goodbye!\n";

	// return is a C++ keyword.
	// If we don't place an explicit return statement at the end of main(),
	// a return 0; statement is inserted automatically.
	// In the program  examples in this book, I do not place an explicit return statement.
	return 0;
}


