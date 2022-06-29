// The test4.cpp Program

/* test4.cpp -- Abstraction */

#include <iostream>

using std::string;

class AbstractEmployee {
	virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee{
private:// defualt
	string Name;
	string Company;
	int Age;

public:
	void setName(string name)
	{
		Name = name;
	}
	string getName(void)
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
	void AskForPromotion(void){
		if(Age > 30)
		{
			std::cout << Name << " got promoted!" << std::endl;
		}
		else
		{
			std::cout << Name << ", sorry No promotion for you!" << std::endl;
		}
	}
protected:
};

class Developer: Emloyee {
pubilc:
	string FavProgrammingLanguage;
};

int main(void)
{
	Employee employee1 = Employee("Saldina", "YT-CodeBeaty", 25);
	Employee employee2 = Employee("John", "Amazon", 35);
//	employee1.AskForPromotion();
//	employee2.AskForPromotion();
	Developer d;

	return 0;
}
