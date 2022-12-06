#include "Bureaucrat.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

Bureaucrat::Bureaucrat(void) : _name("")
{
	std::cout << BWHT << this->_name << " Bureaucrat default constructor called." << RES << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	std::cout << BWHT << this->_name << " Bureaucrat name in param constructor called." << RES << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy)
{

	std::cout << BWHT << this->_name << " Bureaucrat copy constructor called." << RES << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << BWHT << this->_name << " Bureaucrat destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	// verif rhs == this
	return (*this);
}

// members functions===========================================================
//=============================================================================
