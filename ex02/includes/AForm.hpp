#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	public:
//______________Constructors an destructor_________________________________
		
		AForm(std::string name, unsigned int grade_sign, unsigned int grade_exec);
		AForm(AForm const &cpy);
		virtual ~AForm(void);

//______________Operator overload___________________________________________

		AForm &operator=(AForm const &rhs);

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

		class AFormAlreadySigned: public std::exception
		{
			const char *what () const throw ();
		};

//______________Members functions______________________________________

		void be_signed(Bureaucrat& bureaucrat);
		virtual void AForm_exectution();

	private:

		AForm(void);
		std::string const	_name;
		unsigned int const	_grade_to_sign;
		unsigned int const	_grade_to_exec;
		bool 				_is_signed;
};

std::ostream& operator<<(std::ostream& o, AForm const& i);

#endif