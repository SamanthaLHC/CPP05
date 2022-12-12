#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
	//______________Constructors an destructor_________________________________

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &cpy);
	~PresidentialPardonForm(void);

	//______________Operator overload___________________________________________

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	//______________Accessors___________________________________________________

	std::string get_target();

	//______________Members functions___________________________________________

	void execute(Bureaucrat const &executor) const;

	//______________Exception___________________________________________________

	class NotSignedException : public std::exception
	{
		const char *what() const throw();
	};

	private :
		// default construct unavailable
		PresidentialPardonForm(void);
		std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif