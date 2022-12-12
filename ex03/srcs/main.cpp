#include "colors.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		try
		{
			Intern someRandomIntern;
			AForm *rrf;
			rrf = someRandomIntern.make_form("robotomy request", "Bender");
			std::cout << rrf << std::endl;
		}
		catch (const std::exception &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
}
