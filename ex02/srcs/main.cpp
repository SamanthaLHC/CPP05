#include "colors.h"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << BCYN << "________CHECK FORM SIGNATURE___________" << RES << std::endl;
		std::cout << std::endl;
		Form form_to_sign("Earth's destruction approval", 20, 20);
		std::cout << form_to_sign << std::endl;
		try
		{
			Bureaucrat vogon("Prostnetic Vogon Jeltz", 1);
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____should sign a form: _____" << RES << std::endl;
			vogon.sign_form(form_to_sign);
			std::cout << form_to_sign << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		Form form_to_sign("Earth's destruction approval", 20, 20);
		std::cout << form_to_sign << std::endl;
		try
		{
			std::cout << BBLU << "_____check the case where he could not sign because of low grade: ____" << RES << std::endl;
			std::cout << std::endl;
			Bureaucrat vogon("Prostnetic Vogon Jeltz", 34);
			std::cout << vogon << std::endl;
			vogon.sign_form(form_to_sign);
			std::cout << form_to_sign << std::endl;
			std::cout << BBLU << "___ promotion + attempt to sign again: ____" << RES << std::endl;
			std::cout << std::endl;
			std::cout << "grade before promotion: " << vogon.get_grade() << std::endl;
			vogon.promotion_grade(14);
			std::cout << "grade after promotion: " << vogon.get_grade() << std::endl;
			std::cout << vogon.get_grade() << std::endl;
			vogon.sign_form(form_to_sign);
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		std::cout << BCYN << "________CHECK ANOTHERS ERRORS FORM SIGNATURE___________" << RES << std::endl;
		std::cout << std::endl;
		Form form_to_sign("Earth's destruction approval", 20, 20);
		std::cout << form_to_sign << std::endl;
		try
		{
			std::cout << std::endl;
			Bureaucrat vogon("Prostnetic Vogon Jeltz", 5);
			Bureaucrat vogon_general("Kwaltz", 1);
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____Jeltz should sign a form: _____" << RES << std::endl;
			vogon.sign_form(form_to_sign);
			std::cout << form_to_sign << std::endl;
			std::cout << vogon_general << std::endl;
			std::cout << BBLU << "_____Kwaltz want to sign it but it is already signed: _____" << RES << std::endl;
			vogon_general.sign_form(form_to_sign);
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
}
