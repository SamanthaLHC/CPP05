#include "colors.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{

	std::cout << BCYN << "________CHECK INTERN'S SHRUBBERY CREATION___________" << RES << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			Bureaucrat random_vogon("Zarniwoop", 120);
			AForm *rrf;
			std::cout << BBLU << "_____should create shrubbery form: _____" << RES << std::endl;
			rrf = someRandomIntern.make_form("shrubbery creation", "Bender");
			std::cout << *rrf << std::endl;
			rrf->be_signed(random_vogon);
			std::cout << BBLU << "_____should plant trees: _____" << RES << std::endl;
			random_vogon.execute_form(*rrf);
			delete rrf;
		}
		catch (const std::exception &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	std::cout << BCYN << "________CHECK INTERN'S ROBOTOMY CREATION___________" << RES << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			Bureaucrat random_vogon("Zarniwoop", 12);
			AForm *rrf;
			std::cout << BBLU << "_____should create robotomy form: _____" << RES << std::endl;
			rrf = someRandomIntern.make_form("robotomy request", "Bender");
			std::cout << *rrf << std::endl;
			rrf->be_signed(random_vogon);
			std::cout << BBLU << "_____should heard drill and perform robotomy: _____" << RES << std::endl;
			random_vogon.execute_form(*rrf);
			delete rrf;
		}
		catch (const std::exception &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	std::cout << BCYN << "________CHECK INTERN'S PRESIDENTIAL PARDON CREATION___________" << RES << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			Bureaucrat random_vogon("Zarniwoop", 1);
			AForm *rrf;
			std::cout << BBLU << "_____should create shrubbery form: _____" << RES << std::endl;
			rrf = someRandomIntern.make_form("presidential pardon", "Bender");
			std::cout << *rrf << std::endl;
			rrf->be_signed(random_vogon);
			std::cout << BBLU << "_____should have a presidential pardon: _____" << RES << std::endl;
			random_vogon.execute_form(*rrf);
			delete rrf;
		}
		catch (const std::exception &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	std::cout << BCYN << "________CHECK INVALID FORM___________" << RES << std::endl;
	std::cout << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			Bureaucrat random_vogon("Zarniwoop", 120);
			AForm *rrf;
			std::cout << BBLU << "_____should throw an exception: _____" << RES << std::endl;
			rrf = someRandomIntern.make_form("pouet", "Bender");
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch (const std::exception &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
}
