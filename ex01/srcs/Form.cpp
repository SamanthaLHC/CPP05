#include "Form.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

Form::Form(void) : _name(""), _grade_to_sign(0), _grade_to_exec(0), _is_signed(false)
{
	std::cout << BWHT << this->_name << " Form default constructor called." << RES << std::endl;
	return;
}

Form::Form(std::string name, unsigned int grade_sign, unsigned int grade_exec) : _name(name),
 _grade_to_sign(grade_sign), _grade_to_exec(grade_exec), _is_signed(false)
{
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw GradeTooHighException();
	else if (this->_grade_to_sign > 150 || this->_grade_to_exec > 150)
		throw GradeTooLowException();
	else
		std::cout << BWHT << this->_name << " Form NAME constructor called." << RES << std::endl;
	return;
}

Form::Form(Form const &cpy) : _name(cpy._name), _grade_to_sign(cpy._grade_to_sign),
							 _grade_to_exec(cpy._grade_to_exec), _is_signed(cpy._is_signed)
{
	std::cout << BWHT << this->_name << " Form copy constructor called." << RES << std::endl;
	*this = cpy;
}

Form::~Form(void)
{
	std::cout << BWHT << this->_name << " Form destructor called" << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_is_signed = rhs.get_signed_status();
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, Form const &input)
{
	out_stream << BMAG << "Form title: " << input.get_name() << std::endl;
	out_stream << BMAG << "Grade required to sign: " << input.get_grade_to_sign() << std::endl;
	out_stream << BMAG << "Grade required to exec: " << input.get_grade_to_exec() << std::endl;
	out_stream << BMAG << "already signed : " << input.get_signed_status() <<std::endl;
	return out_stream;
}

// accessors ==================================================================
//=============================================================================

std::string Form::get_name() const
{
	return this->_name;
}

unsigned int Form::get_grade_to_sign() const
{
	return this->_grade_to_sign;
}

unsigned int Form::get_grade_to_exec() const
{
	return this->_grade_to_exec;
}

bool Form::get_signed_status() const
{
	return this->_is_signed;
}

// Exceptions handler =========================================================
//=============================================================================

const char *Form::GradeTooHighException::what() const throw()
{
	return "Bad grade status: way too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Bad grade status: way too low.";
}

// members functions ==========================================================
//=============================================================================

// promotion_grade() and demotion_grade() should be use in try/ catch scope in order
// to avoid crash (because of the throw here)

void Form::be_signed(Bureaucrat& bureaucrat)
{
	if (this->_grade <= 1 || ((this->_grade -= grade) <= 1))
		throw GradeTooHighException();
}