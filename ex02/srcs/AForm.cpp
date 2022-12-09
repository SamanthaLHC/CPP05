#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

AForm::AForm(void) : _name(""), _grade_to_sign(0), _grade_to_exec(0), _is_signed(false)
{
	std::cout << BWHT << this->_name << " AForm default constructor called." << RES << std::endl;
	return;
}

AForm::AForm(std::string name, unsigned int grade_sign, unsigned int grade_exec) : _name(name),
 _grade_to_sign(grade_sign), _grade_to_exec(grade_exec), _is_signed(false)
{
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw GradeTooHighException();
	else if (this->_grade_to_sign > 150 || this->_grade_to_exec > 150)
		throw GradeTooLowException();
	else
		std::cout << BWHT << this->_name << " AForm NAME constructor called." << RES << std::endl;
	return;
}

AForm::AForm(AForm const &cpy) : _name(cpy._name), _grade_to_sign(cpy._grade_to_sign),
							 _grade_to_exec(cpy._grade_to_exec), _is_signed(cpy._is_signed)
{
	std::cout << BWHT << this->_name << " AForm copy constructor called." << RES << std::endl;
	*this = cpy;
}

AForm::~AForm(void)
{
	std::cout << BWHT << this->_name << " AForm destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->_is_signed = rhs.get_signed_status();
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, AForm const &input)
{
	out_stream << BMAG << "Form title: " << input.get_name() << std::endl;
	out_stream << BMAG << "Grade required to sign: " << input.get_grade_to_sign() << std::endl;
	out_stream << BMAG << "Grade required to exec: " << input.get_grade_to_exec() << std::endl;
	out_stream << BMAG << "already signed : " << input.get_signed_status() <<std::endl;
	return out_stream;
}

// accessors ==================================================================
//=============================================================================

std::string AForm::get_name() const
{
	return this->_name;
}

unsigned int AForm::get_grade_to_sign() const
{
	return this->_grade_to_sign;
}

unsigned int AForm::get_grade_to_exec() const
{
	return this->_grade_to_exec;
}

bool AForm::get_signed_status() const
{
	return this->_is_signed;
}

// Exceptions handler =========================================================
//=============================================================================

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Bad grade status: way too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Bad grade status: way too low.";
}

const char *AForm::AFormAlreadySigned::what() const throw()
{
	return "AForm already signed.";
}

// members functions ==========================================================
//=============================================================================

// be_signed should be use in try/ catch scope in order
// to avoid crash (because of the throw here)

void AForm::be_signed(Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() > this->_grade_to_sign)
		throw GradeTooLowException();
	if (this->_is_signed == true)
		throw AFormAlreadySigned();
	else
		this->_is_signed = true;
}