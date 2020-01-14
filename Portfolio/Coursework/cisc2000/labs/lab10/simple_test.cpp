//DISPLAY 15.7 Using Derived Classes
#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"
using namespace std;

int main( )
{
   Employee * employees[3];
   Employee  employeeArray[3];
    string name, ssn;
    double rate;
    int hour;
    double salary;
    string title;

    for (int i=0;i<3;i++)
    {
	cout <<"Enter employee #"<<i<<":\n";
	string type; 
        cout <<"Enter the type of employee (hourly, salaried, admin):";
        cin >> type;

        //common information for all kinds of employees
        cout <<"Name:";
        cin >> name; 

        cout <<"SSN: ";
        cin >> ssn; 

	if (type=="hourly")
	{
		HourlyEmployee * employee = new HourlyEmployee;
    		employee->set_name(name);
    		employee->set_ssn(ssn); 

		HourlyEmployee anotherOne (*employee);

		cout <<"Hourly rate:";
		cin >> rate;
    		employee->set_rate(rate);
		
		cout <<"How many hours:";
		cin >> hour;

    		employee->set_hours(hour);
    		cout << "Check for " << employee->get_name( )
         		<< " for " << employee->get_hours( ) << " hours.\n";
    		employee->print_check( );
    		cout << endl;

		employees[i] = employee;
	} else if (type=="salaried")
	{
		cout <<"Salary:";
		cin >> salary;
    		SalariedEmployee * boss = new SalariedEmployee(name,ssn, salary);
    		cout << "Check for " << boss->get_name( ) << endl;
    		boss->print_check( ); 

		/* This produces an error
		cout <<"calling the Employee's print_check\n";
		boss->Employee::print_check();
		*/

		//cout <<"Trying to access private member\n";
		//cout <<"Name of boss" << boss->name << endl;


		employees[i] = boss;
	} else if (type=="admin")
	{
   		//Test your Administrator class here... 
   		cout <<"Enter title:";
		string t;
		cin >> t;
	
		cout <<"Enter salary:";
		cin >> salary;

		Administrator * admin = new Administrator (name,ssn,salary,t);
		
		cout <<"Print check for administrator employee\n";
		(*admin).print_check();

		employees[i] = admin;
   	}
   }


   //Payday! 
   
   cout <<"***********************************************\n";
   cout <<"Payday! Print all checks in a batch!\n";
   for (int i=0;i<3;i++)
   {
	  employees[i]->print_check ();
   }

    //free up dynamically allocated memory
    for (int i=0;i<3;i++)
          delete employees[i];
    return 0;
}
