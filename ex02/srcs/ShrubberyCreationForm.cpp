#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

#include <fstream>

// constructs ans destruct======================================================
//=============================================================================

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("non_valid_form", 0, 0)
{
	this->_target = "unkwowm";
	std::cout << BWHT << this->get_name() << " ShrubberyCreationForm default constructor called." << RES << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery", 145, 137)
{
	this->_target = target;
	if (this->get_grade_to_sign() < 1 || this->get_grade_to_exec() < 1)
		throw GradeTooHighException();
	else if (this->get_grade_to_sign() > 145 || this->get_grade_to_exec() > 137)
		throw GradeTooLowException();
	else
	{
		std::cout << BWHT << this->get_name() << " ShrubberyCreationForm NAME constructor called."
				  << RES << std::endl;
	}
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy)
	: AForm("shrubbery", 145, 137)
{
	std::cout << BWHT << this->get_name() << " ShrubberyCreationForm copy constructor called."
			  << RES << std::endl;
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << BWHT << this->get_name() << " ShrubberyCreationForm destructor called"
			  << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
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

// Exceptions handler =========================================================
//=============================================================================

std::string ShrubberyCreationForm::get_target()
{
	return this->_target;
}

// members functions ==========================================================
//=============================================================================


void ShrubberyCreationForm::create_file_and_plant_trees(std::string target) const
{
	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if(file.fail())
	{
		std::cout << BRED << "ERROR: file could not be created." << RES << std::endl;
		return;
	}
	file.open(filename.c_str(), std::ios::out | std::ios::trunc);
	file << "        /\\       " << std::endl; 
    file << "       / *\\      " << std::endl; 
    file << "      /*  *\\     " << std::endl; 
    file << "     /*   * \\    " << std::endl; 
    file << "    /   *    \\   " << std::endl; 
    file << "   /  *     * \\  " << std::endl; 
    file << "  / _ _   * _ _\\ " << std::endl; 
    file << "        ||        " << std::endl; 
    file << "        ||        " << std::endl; 
    file << "        ||        " << std::endl;
	file.close();

}

// should be use in try/ catch scope in order
// to avoid crash (because of the throw here)
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.get_grade() > this->get_grade_to_exec())
		throw GradeTooLowException();
	else if (this->get_signed_status() == false)
		throw AFormAlreadySigned();
	else
		this->create_file_and_plant_trees(this->_target);
}
