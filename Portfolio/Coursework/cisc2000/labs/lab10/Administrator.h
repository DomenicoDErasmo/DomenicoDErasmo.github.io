/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional members:
 *  1. a string type member variable to store the title (director, Vice President, ... )
 *  3. Constructor functions: one default one, another taking necessary info. about the administrator: name, SSN, salary, title
 *  4. redefine print_check() so that the title is printed on the check. Start with the version from 
 *  SalariedEmployee
 */
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator:public SalariedEmployee
{
  public:
	// default constructor
	Administrator();

	// constructor for admin
	Administrator(string name, string SSN, double salary, string title); 

	// gets administrator title
	std::string getTitle() const {return title;};

	// allows user to edit administrator title
	void changeTitle(std::string input) {title = input;};

	// creates the check for the employee
	void print_check();

  private: 
	// gives title of worker, such as director, Vice President...
	std::string title;
};

#endif
