// The test1.cpp Program

/* test1.cpp -- Access modifiers in public */

#include <iostream>

using std::string;

class Employee{
//private:// default is private
public:
	string Name;
	string Company;
	int Age;

	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << "\n" << std::endl;
	}
};

int main(void)
{
	Employee employee1;
    employee1.Name = "Saldina";
	employee1.Company = "YT-CodeBeaty";
	employee1.Age = 25;
	employee1.IntroduceYourself();

	Employee employee2;
	employee2.Name = "John";
	employee2.Company = "Amazon";
	employee2.Age = 35;
	employee2.IntroduceYourself();

	return 0;
}
