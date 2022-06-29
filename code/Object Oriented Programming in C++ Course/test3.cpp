// The test3.cpp Program

/* test3.cpp -- Encapsulation */

#include <iostream>

using std::string;

class Employee{
private:// defualt
	string Name;
	string Company;
	int Age;

public:
	void setName(string name)	// setter
	{
		Name = name;
	}
	string getName(void)		// getter
	{
		return Name;
	}
	void setCompany(string company)
	{
		Company = company;
	}
	string getCompany(void)
	{
		return Company;
	}
	void setAge(int age)
	{
		if ( age >= 18 )
		{
			Age = age;
		}
	}
	int getAge(void)
	{
		return Age;
	}
	
	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << "\n" << std::endl;
	}
	Employee(string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}
protected:
};


int main(void)
{
	Employee employee1 = Employee("Saldina", "YT-CodeBeaty", 25);
	employee1.IntroduceYourself();

	Employee employee2 = Employee("John", "Amazon", 35);
	employee2.IntroduceYourself();

	employee1.setAge(39);
	std::cout << employee1.getName() << " is " << employee1.getAge() << " years old\n" << std::endl;

	return 0;
}
