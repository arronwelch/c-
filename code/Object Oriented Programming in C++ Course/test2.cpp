// The test2.cpp Program

/* test2.cpp -- Constructors has the same name with class */

#include <iostream>

using std::string;

class Employee{
private:
	string Name;
	string Company;
	int Age;

public:
	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << "\n" << std::endl;
	}
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
};

int main(void)
{
	Employee employee1 = {"Saldina", "YT-CodeBeaty", 25};
	//Employee employee1 = Employee("Saldina", "YT-CodeBeaty", 25);
	employee1.IntroduceYourself();

	Employee employee2 = {"John", "Amazon", 35};
	//Employee employee2 = Employee("John", "Amazon", 35);
	employee2.IntroduceYourself();

	return 0;
}
