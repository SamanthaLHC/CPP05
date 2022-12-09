#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

Bureaucrat::Bureaucrat(void) : _name(""), _grade(0)
{
	std::cout << BWHT << this->_name << " Bureaucrat default constructor called." << RES << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
	else
		std::cout << BWHT << this->_name << " Bureaucrat NAME constructor called." << RES << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) : _name(cpy._name)
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
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, Bureaucrat const &input)
{
	out_stream << BMAG << input.get_name() << ", bureaucrate grade "
			   << input.get_grade() << RES;
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

// Exceptions handler =========================================================
//=============================================================================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade range error: way too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade range error: way too low.";
}

// members functions ==========================================================
//=============================================================================

// promotion_grade() and demotion_grade() should be use in try/ catch scope in order
// to avoid crash (because of the throw here)

void Bureaucrat::promotion_grade(unsigned int grade)
{
	if (this->_grade <= 1 || ((this->_grade -= grade) <= 1))
		throw GradeTooHighException();
}

void Bureaucrat::demotion_grade(unsigned int grade)
{
	if (this->_grade >= 150 || ((this->_grade += grade) >= 150))
		throw GradeTooLowException();
}

void Bureaucrat::sign_form(AForm &form_to_sign)
{
	try
	{
		form_to_sign.be_signed(*this);
		std::cout << BYEL << this->_name << " signed " << form_to_sign.get_name()
				  << RES<< std::endl;
	}
	catch(const std::exception& err)	
	{
		std::cerr << BRED << this->_name << " couldn't sign " << form_to_sign.get_name()
		<< " because: " << err.what() << std::endl;
	}
}

void Bureaucrate::execute_form(Form const & form)
{
	try
	{

	}
	catch(const std::exception& err)	
	{
		std::cerr << BRED << this->_name << " couldn't execute " << form.get_name()
		<< " because: " << err.what() << std::endl;
	}
}
