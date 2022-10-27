
#include <iostream>
#include "4.3.h"

int main()
{
	cout << "Hello, Exercise 4.3!\n";

	GlobalData gd1("gd_name1", "V1_1", 1, 12, 123);
	//gd1.display(gd1);
	gd1.display();
	cout << endl;

	GlobalData gd2("gd_name2", "V1_1", 1, 12, 123);
	//gd2.display(gd2);
	gd2.display();
	GlobalData::set_tests_run(89);
	cout << endl;
	//gd1.display(gd2);// static is shared
	gd1.display();// static is shared
	cout << endl;
}
