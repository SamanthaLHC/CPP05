#include "colors.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	{
		std::cout << BCYN << "________CHECK EXEC SHRUBBERY___________" << RES << std::endl;
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm form("xmas Vogsphere's garden plantation");
			std::cout << form << std::endl;
			Bureaucrat random_vogon("Zarniwoop", 120);
			std::cout << random_vogon << std::endl;
			Bureaucrat vogon("vogon guard", 120);
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____execution rejected because form was not signed: _____" << RES << std::endl;
			vogon.execute_form(form);
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____should plant a tree: _____" << RES << std::endl;
			random_vogon.sign_form(form);
			vogon.execute_form(form);
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____execution rejected because of low grade: _____" << RES << std::endl;
			Bureaucrat newbie("new bureaucrat", 150);
			newbie.execute_form(form);
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << BCYN << "________CHECK PRESIDENTIAL FORM___________" << RES << std::endl;
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm form("Sam");
			std::cout << form << std::endl;
			Bureaucrat high_vogon("Kwaltz", 3);
			Bureaucrat vogon("Jeltz", 15);
			
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____execution rejected because form was not signed: _____" << RES << std::endl;
			high_vogon.execute_form(form);
			std::cout << BBLU << "_____President forgive: _____" << RES << std::endl;
			vogon.sign_form(form);
			high_vogon.execute_form(form);
			std::cout << BBLU << "_____execution rejected because of low grade: _____" << RES << std::endl;
			Bureaucrat newbie("new bureaucrat", 150);
			newbie.execute_form(form);
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << BCYN << "________CHECK Robotomy___________" << RES << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm form("Newbie");
			std::cout << form << std::endl;
			Bureaucrat high_vogon("Kwaltz", 3);
			Bureaucrat vogon("Jeltz", 15);
			
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____execution rejected because form was not signed: _____" << RES << std::endl;
			high_vogon.execute_form(form);
			std::cout << BBLU << "_____Robotomy: _____" << RES << std::endl;
			vogon.sign_form(form);
			high_vogon.execute_form(form);
			std::cout << BBLU << "_____execution rejected because of low grade: _____" << RES << std::endl;
			Bureaucrat newbie("new bureaucrat", 150);
			newbie.execute_form(form);
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
}
