#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "colors.h"

#include <cstdlib>
#include <ctime>

// constructs ans destruct======================================================
//=============================================================================

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("non_valid_form", 0, 0)
{
	this->_target = "unkwowm";
	std::cout << BWHT << this->get_name() << " RobotomyRequestForm default constructor called." << RES << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	if (this->get_grade_to_sign() < 1 || this->get_grade_to_exec() < 1)
		throw GradeTooHighException();
	else if (this->get_grade_to_sign() > 72 || this->get_grade_to_exec() > 45)
		throw GradeTooLowException();
	else
	{
		std::cout << BWHT << this->get_name() << " RobotomyRequestForm NAME constructor called."
				  << RES << std::endl;
	}
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
	: AForm("shrubbery", 72, 45)
{
	std::cout << BWHT << this->get_name() << " RobotomyRequestForm copy constructor called."
			  << RES << std::endl;
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << BWHT << this->get_name() << " RobotomyRequestForm destructor called"
			  << RES << std::endl;
	return;
}

// operator overload===========================================================
//=============================================================================

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

std::ostream &operator<<(std::ostream &out_stream, RobotomyRequestForm const &input)
{
	out_stream << BMAG << "RobotomyRequestForm title: " << input.get_name() << std::endl;
	out_stream << BMAG << "Grade required to sign: " << input.get_grade_to_sign() << std::endl;
	out_stream << BMAG << "Grade required to exec: " << input.get_grade_to_exec() << std::endl;
	out_stream << BMAG << "already signed : " << input.get_signed_status() << std::endl;
	return out_stream;
}

// Exceptions handler =========================================================
//=============================================================================

const char *RobotomyRequestForm::NotSignedException::what() const throw()
{
	return "Form not signed.";
}

// Accessor ===================================================================
//=============================================================================

std::string RobotomyRequestForm::get_target()
{
	return this->_target;
}

// members functions ==========================================================
//=============================================================================

void RobotomyRequestForm::is_successful(std::string target) const
{
	std::cout << BGRN << "* Awfull drill noises can be heard inside the Robotomy room.. *"
			  << RES << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << BYEL << target << " successfully Robotomised!" << RES << std::endl;
	else
		std::cout << BRED << target << " robotomy failed!" << RES << std::endl;
}

// should be use in try/ catch scope in order
// to avoid crash (because of the throw here)
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.get_grade() > this->get_grade_to_exec())
		throw GradeTooLowException();
	else if (this->get_signed_status() == false)
		throw NotSignedException();
	else
		this->is_successful(this->_target);
}
