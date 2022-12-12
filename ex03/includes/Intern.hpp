#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

class AForm;

class Intern
{
	public:
	//______________Constructors an destructor_________________________________

		Intern(void);
		Intern(Intern const &cpy);
		~Intern(void);

	//______________Operator overload___________________________________________

		Intern &operator=(Intern const &rhs);

	//______________Exceptions__________________________________________________

		class NotAFormException : public std::exception
		{
			const char *what() const throw();
		};

	//______________Members functions___________________________________________

		AForm *make_form(std::string form, std::string target);

	private:

		AForm *create_shrubbery(std::string target);
		AForm *create_presidential_pardon(std::string target);
		AForm *create_robotomy(std::string target);

};

std::ostream &operator<<(std::ostream &o, Intern const &i);

#endif