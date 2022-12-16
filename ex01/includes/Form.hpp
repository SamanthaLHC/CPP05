#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
//______________Constructors an destructor_________________________________
		
		Form(std::string const name, unsigned int grade_sign, unsigned int grade_exec);
		Form(Form const &cpy);
		~Form(void);

//______________Operator overload___________________________________________

		Form &operator=(Form const &rhs);

//______________Accessors__________________________________________________

		std::string get_name() const;
		unsigned int get_grade_to_sign() const;
		unsigned int get_grade_to_exec() const;
		bool get_signed_status() const;

//______________Exceptions__________________________________________________

		class GradeTooHighException: public std::exception
		{
			const char *what () const throw ();
		};

		class GradeTooLowException: public std::exception
		{
			const char *what () const throw ();
		};

		class FormAlreadySigned: public std::exception
		{
			const char *what () const throw ();
		};

//______________Members functions______________________________________

		void be_signed(Bureaucrat& bureaucrat);

	private:

		Form(void);
		std::string const	_name;
		unsigned int const	_grade_to_sign;
		unsigned int const	_grade_to_exec;
		bool 				_is_signed;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif