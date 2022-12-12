#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

#include <fstream>

// constructs ans destruct======================================================
//=============================================================================

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("non_valid_form", 0, 0)
{
	this->_target = "unkwowm";
	std::cout << BWHT << this->get_name() << " PresidentialPardonForm default constructor called." << RES << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	this->_target = target;
	if (this->get_grade_to_sign() < 1 || this->get_grade_to_exec() < 1)
		throw GradeTooHighException();
	else if (this->get_grade_to_sign() > 145 || this->get_grade_to_exec() > 137)
		throw GradeTooLowException();
	else
	{
		std::cout << BWHT << this->get_target() << " PresidentialPardonForm NAME constructor called."
				  << RES << std::endl;
	}
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy)
	: AForm("Presidential Form", 25, 5)
{
	std::cout << BWHT << this->get_name() << " PresidentialPardonForm copy constructor called."
			  << RES << std::endl;
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << BWHT << this->get_name() << " PresidentialPardonForm destructor called"
			  << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, PresidentialPardonForm const &input)
{
	out_stream << BMAG << "PresidentialPardonForm title: " << input.get_name() << std::endl;
	out_stream << BMAG << "Grade required to sign: " << input.get_grade_to_sign() << std::endl;
	out_stream << BMAG << "Grade required to exec: " << input.get_grade_to_exec() << std::endl;
	out_stream << BMAG << "already signed : " << input.get_signed_status() << std::endl;
	return out_stream;
}

// Exceptions handler =========================================================
//=============================================================================

const char *PresidentialPardonForm::NotSignedException::what() const throw()
{
	return "Form not signed.";
}

// Accessor =========================================================
//=============================================================================

std::string PresidentialPardonForm::get_target()
{
	return this->_target;
}

// members functions ==========================================================
//=============================================================================

// should be use in try/ catch scope in order
// to avoid crash (because of the throw here)
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.get_grade() > this->get_grade_to_exec())
		throw GradeTooLowException();
	else if (this->get_signed_status() == false)
		throw NotSignedException();
	else
		std::cout << BYEL << "Zaphod Beeblebrox forgive " << this->_target
				  << RES << std::endl;
}
