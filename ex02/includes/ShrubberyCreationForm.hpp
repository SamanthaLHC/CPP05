#ifndef SHRUBBERYCREATIONShrubberyCreationForm_HPP
#define SHRUBBERYCREATIONShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	//______________Constructors an destructor_________________________________

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
	~ShrubberyCreationForm(void);

	//______________Operator overload___________________________________________

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	//______________Members functions______________________________________

	void be_signed(Bureaucrat &bureaucrat);
	void create_file_and_plant_trees();

private:
	//default construct unavailable
	ShrubberyCreationForm(void);
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif