#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

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

	//______________Accessors______________________________________

	std::string get_target();

	//______________Members functions______________________________________

	void execute(Bureaucrat const &executor) const;
	void create_file_and_plant_trees(std::string target) const;

private:
	// default construct unavailable
	ShrubberyCreationForm(void);
	std::string _target;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif