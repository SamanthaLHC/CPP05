#include "colors.h"
#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << BCYN << "________CHECK LOW EXCEPTION____________" << RES << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat vogon("vogon guard", 150);
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____should throw an exception: _____" << RES << std::endl;
			vogon.demotion_grade();
			std::cout << vogon << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << BCYN << "________CHECK HIGH EXCEPTION____________" << RES << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat vogon("Prostnetic vogon Kwaltz", 1);
			std::cout << vogon << std::endl;
			std::cout << BBLU << "_____should throw an exception: _____" << RES << std::endl;
			vogon.promotion_grade();
			std::cout << vogon << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << BCYN << "________CHECK A GOOD PROMOTION____________" << RES << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat vogon("Prostnetic Vogon Jeltz", 10);
			std::cout << vogon.get_grade() << std::endl;
			std::cout << vogon << std::endl;
			vogon.promotion_grade();
			std::cout << vogon.get_grade() << std::endl;

			std::cout << vogon << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
		std::cout << std::endl;
		std::cout << BCYN << "________CHECK A GOOD DEMOTION____________" << RES << std::endl;
		std::cout << std::endl;
		try
		{
			Bureaucrat vogon("Prostnetic Vogon Jeltz", 10);
			std::cout << vogon << std::endl;
			vogon.demotion_grade();
			std::cout << vogon << std::endl;
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << BCYN << "________CHECk A BAD INSTANCIATION____________" << RES << std::endl;
		std::cout << std::endl;

		try
		{
			{
				Bureaucrat vogon("Zarniwoop", 156);
			}
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
	{
		try
		{
			{
				Bureaucrat vogon("Zarniwoop", 0);
			}
		}
		catch (std::exception const &err)
		{
			std::cerr << BRED << err.what() << RES << std::endl;
		}
	}
}
