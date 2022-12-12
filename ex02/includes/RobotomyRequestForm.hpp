#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
	//______________Constructors an destructor_________________________________

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &cpy);
	~RobotomyRequestForm(void);

	//______________Operator overload___________________________________________

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	//______________Accessors___________________________________________________

	std::string get_target();

	//______________Members functions___________________________________________

	void execute(Bureaucrat const &executor) const;
	void is_successful(std::string target) const;

	//______________Exception___________________________________________________

	class NotSignedException : public std::exception
	{
		const char *what() const throw();
	};

	private :
		// default construct unavailable
		RobotomyRequestForm(void);
		std::string _target;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif