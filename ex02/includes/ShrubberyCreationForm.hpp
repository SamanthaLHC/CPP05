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

	//______________Accessors___________________________________________________

	std::string get_target();

	//______________Members functions___________________________________________

	void execute(Bureaucrat const &executor) const;
	void create_file_and_plant_trees(std::string target) const;

	//______________Exception___________________________________________________

	class NotSignedException : public std::exception
	{
		const char *what() const throw();
	};

	private :
		// default construct unavailable
		ShrubberyCreationForm(void);
		std::string _target;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif