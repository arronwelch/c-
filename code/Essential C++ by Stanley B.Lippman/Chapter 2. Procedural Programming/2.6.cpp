// 2.6 Providing Overloaded Functions
#include <iostream>
#include <string>

using namespace std;

void display_message(char);
void display_message(const string &);
void display_message(const string &, int);
void display_message(const string &, int, int);

bool is_size_ok(int size)
{
	const int max_size = 1024;
	const string msg("Requested size is not supported");

	if (size <= 0 || size > max_size) {
		display_message(msg, size);
		return false;
	}
	return true;
}

int main(void)
{

}

void display_message(const string &msg, int size)
{

}
