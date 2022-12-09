#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

// constructs ans destruct======================================================
//=============================================================================

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("non_valid_form", 0, 0)
{
	this->_already_executed_flag = false;
	this->_target = "unkwowm";
	std::cout << BWHT << this->get_name() << " ShrubberyCreationForm default constructor called." << RES << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery", 145, 137)
{
	this->_already_executed_flag = false;
	this->_target = target;
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
	out_stream << BMAG << "already signed : " << input.get_signed_status() << std::endl;
	return out_stream;
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

const char *ShrubberyCreationForm::ShrubberyCreationFormAlreadyExecuted::what() const throw()
{
	return "ShrubberyCreationForm already executed.";
}

// Exceptions handler =========================================================
//=============================================================================

std::string ShrubberyCreationForm::get_target()
{
	return this->_target;
}

// members functions ==========================================================
//=============================================================================

// should be use in try/ catch scope in order
// to avoid crash (because of the throw here)

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (executor.get_grade_to_exec() > 137)
		throw GradeTooLowException();
	if (this->_already_executed_flag == true)
		throw ShrubberyCreationFormAlreadyExecuted();
	else
	{
		this->_already_executed_flag = true;
		executor.create_file_and_plant_trees(this->_target);
	}
}

void ShrubberyCReationForm::create_file_and_plant_trees(std::string target)
{
	
}
