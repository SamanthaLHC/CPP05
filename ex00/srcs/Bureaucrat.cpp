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
	if (rhs != this)
	{
		this->_grade = rhs._grade;
		this->_name = rhs._name;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, Bureaucrat const &input)
{
	out_stream << input.get_name() << ", bureaucrate grade " << input.get_grade();
	return out_stream;
}

// accessors ==================================================================
//=============================================================================

std::string Bureaucrat::get_name() const
{
	return this->_name;
}

unsigned int Bureaucrat::get_grade() const
{
	return this->_grade;
}

// members functions ==========================================================
//=============================================================================

void promotion_grade(unsigned int grade)
{
	//here use exception
}

void demotion_grade(unsigned int grade)
{
	//here use exception
}