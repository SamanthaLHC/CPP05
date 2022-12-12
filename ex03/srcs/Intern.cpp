#include "Intern.hpp"
#include "AForm.hpp"
#include "colors.h"

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// constructs ans destruct======================================================
//=============================================================================

Intern::Intern(void)
{
	std::cout << BWHT << " Intern default constructor called." << RES << std::endl;
	return;
}

Intern::Intern(Intern const &cpy)
{
	std::cout << BWHT << " Intern copy constructor called." << RES << std::endl;
	*this = cpy;
}

Intern::~Intern(void)
{
	std::cout << BWHT << " Intern destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, Intern const &input)
{
	(void)input;
	out_stream << BMAG << "Info : Just a random intern trying to climb the ladder.." << RES;
	return out_stream;
}

// Exceptions =================================================================
//=============================================================================

const char *Intern::NotAFormException::what() const throw()
{
	return "This Form doesn't exist. Can not be created.";
}

// members functions ==========================================================
//=============================================================================

AForm *Intern::create_shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::create_presidential_pardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::create_robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

// should be use in try/ catch scope in order
//  to avoid crash (because of the throw here)
AForm *Intern::make_form(std::string form_request, std::string target)
{

	AForm *(Intern::*func_list[3])(std::string) = {&Intern::create_shrubbery, &Intern::create_presidential_pardon, 
							&Intern::create_robotomy};
	std::string form_name[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	for  (int i = 0; i < 3; i++)
	{
		if (form_name[i] == form_request)
		{
			std::cout << BYEL << "Intern creates " << form_request << " for " << target
					  << RES << std::endl;
			return (this->*func_list[i])(target);
		}
	}
	throw NotAFormException();
}
