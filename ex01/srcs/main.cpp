#include "colors.h"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
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
	}
	catch (std::exception const &err)
	{
		std::cerr << BRED << err.what() << RES << std::endl;
	}
	try
	{
		Bureaucrat vogon("Prostnetic Vogon Jeltz", 34);
		std::cout << vogon << std::endl;
		std::cout << BBLU << "_____check the case where he could not sign: _____" << RES << std::endl;
		vogon.sign_form(form_to_sign);
	}
	catch (std::exception const &err)
	{
		std::cerr << BRED << err.what() << RES << std::endl;
	}
}
