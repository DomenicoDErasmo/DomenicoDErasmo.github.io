/* Implement Administrator class */
#include <iostream>
#include "Administrator.h"

// default constructor
Administrator::Administrator():SalariedEmployee()
{
	// deliberately empty
	std::cout << "Administrator() called\n";	
}

// creates an administrator with the given name, ssn, and weekly salary
Administrator::Administrator(std::string name, std::string SSN, double weeklySalary, std::string title)
{
	Employee::set_name(name);
	Employee::set_ssn(SSN);
	SalariedEmployee::set_salary(weeklySalary);
	changeTitle(title);
	std::cout << "Administrator (" << name << ", " << SSN << ", " << weeklySalary << ", " << title << ") called\n";
}

// formats check
void Administrator::print_check() 
{
	set_net_pay(get_salary());
	std::cout << "\n_______________________________________________\n";
	std::cout << "Pay to the order of " << get_name() << "\n";
	std::cout << "The sum of " << get_net_pay() << " Dollars \n";
	std::cout << "_______________________________________________\n";
	std::cout << "Check Stub NOT NEGOTIABLE \n";
	std::cout << "Employee Number: " << get_ssn() << "\n";
	std::cout << "Salaried Employee - Administrator (" << title << "). Regular Pay: " << get_salary() << "\n";
	std::cout << "_______________________________________________\n";
}

