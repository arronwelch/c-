# Essential C++ By Stanley B. Lippman
"Readers can pick up this book and become familiar with C++ in a short time."

## 1.1 How to Write a C++ Program
We start in the same place every C++ program starts -- in a function called ```main()```.
```main()``` is a user-implemented function of the following general form:
```c++
// main.cpp
int main()
{
	// our program code goes here
}
```
```int``` is a C++ language keyword.*```Keywords```* are predefined names given special meaning
 within the language.
```c++
#include <iostream>
```
The standard C++ input/output library is called the *```iostream```* library.
It consists of a collection of related classes supporting input and output to the user's
terminal and to files.
```c++
cout << "Please enter your first name: ";
```
To write to the user's terminal, we use a predefined class object named ```cout```
(pronounced *```see out```*).
```
// Pseudo code: General logic of our program
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
```
IAfter a ```case``` label is matched, all the ```case``` labels following the matched ```case```
label are also executed unless we explicitly break off execution.This is what the ```break```
statement does. Why, you're probably asking, is the ```switch``` statement designed this way?
Here is an example of this fall-through behavior being just right:
```c++
switch (next_char)
{
	case 'a': case 'A':
	case 'e': case 'E':
	case 'i': case 'I':
	case 'o': case 'O':
	case 'u': case 'U':
		++vowel_cnt:
		break;
	// ...
}
```
