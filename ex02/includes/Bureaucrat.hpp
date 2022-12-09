#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
	public:
//______________Constructors an destructor_________________________________
		
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &cpy);
		~Bureaucrat(void);

//______________Operator overload___________________________________________

		Bureaucrat &operator=(Bureaucrat const &rhs);

//______________Accessors__________________________________________________

		std::string get_name() const;
		unsigned int get_grade() const;

//______________Exceptions__________________________________________________

		class GradeTooHighException: public std::exception
		{
			const char *what () const throw ();
		};

		class GradeTooLowException: public std::exception
		{
			const char *what () const throw ();
		};
//______________Members functions______________________________________

		void promotion_grade(unsigned int grade);
		void demotion_grade(unsigned int grade);
		void sign_form(Form& form_to_sign);


	private:

		Bureaucrat(void);
		std::string const	_name;
		unsigned int 		_grade;

};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif