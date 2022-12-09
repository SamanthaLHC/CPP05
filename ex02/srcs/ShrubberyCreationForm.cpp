#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

ShrubberyCreationForm::ShrubberyCreationForm(void) : _name(""), _grade_to_sign(0), _grade_to_exec(0), _is_signed(false)
{
	std::cout << BWHT << this->_name << " ShrubberyCreationForm default constructor called." << RES << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, unsigned int grade_sign, unsigned int grade_exec) : _name(name),
 _grade_to_sign(grade_sign), _grade_to_exec(grade_exec), _is_signed(false)
{
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw GradeTooHighException();
	else if (this->_grade_to_sign > 150 || this->_grade_to_exec > 150)
		throw GradeTooLowException();
	else
		std::cout << BWHT << this->_name << " ShrubberyCreationForm NAME constructor called." << RES << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : _name(cpy._name), _grade_to_sign(cpy._grade_to_sign),
							 _grade_to_exec(cpy._grade_to_exec), _is_signed(cpy._is_signed)
{
	std::cout << BWHT << this->_name << " ShrubberyCreationForm copy constructor called." << RES << std::endl;
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << BWHT << this->_name << " ShrubberyCreationForm destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_is_signed = rhs.get_signed_status();
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, ShrubberyCreationForm const &input)
{
	out_stream << BMAG << "ShrubberyCreationForm title: " << input.get_name() << std::endl;
	out_stream << BMAG << "Grade required to sign: " << input.get_grade_to_sign() << std::endl;
	out_stream << BMAG << "Grade required to exec: " << input.get_grade_to_exec() << std::endl;
	out_stream << BMAG << "already signed : " << input.get_signed_status() <<std::endl;
	return out_stream;
}

// accessors ==================================================================
//=============================================================================

std::string ShrubberyCreationForm::get_name() const
{
	return this->_name;
}

unsigned int ShrubberyCreationForm::get_grade_to_sign() const
{
	return this->_grade_to_sign;
}

unsigned int ShrubberyCreationForm::get_grade_to_exec() const
{
	return this->_grade_to_exec;
}

bool ShrubberyCreationForm::get_signed_status() const
{
	return this->_is_signed;
}

// Exceptions handler =========================================================
//=============================================================================

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "Bad grade status: way too high.";
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "Bad grade status: way too low.";
}

const char *ShrubberyCreationForm::ShrubberyCreationFormAlreadySigned::what() const throw()
{
	return "ShrubberyCreationForm already signed.";
}

// members functions ==========================================================
//=============================================================================

// be_signed should be use in try/ catch scope in order
// to avoid crash (because of the throw here)

void ShrubberyCreationForm::be_signed(Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() > this->_grade_to_sign)
		throw GradeTooLowException();
	if (this->_is_signed == true)
		throw ShrubberyCreationFormAlreadySigned();
	else
		this->_is_signed = true;
}