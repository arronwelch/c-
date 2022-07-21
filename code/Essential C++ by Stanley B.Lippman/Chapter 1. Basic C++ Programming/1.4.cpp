// 1.4 Writing Conditional and Loop Statements

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
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
}
