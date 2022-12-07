#include <iostream>
#include <string>

class Bureaucrat
{
	public:
//______________Constructors an destructor_________________________________
		
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(Bureaucrat const &cpy);
		~Bureaucrat(void);

//______________Operator overload___________________________________________

		Bureaucrat &operator=(Bureaucrat const &rhs);

//______________Accessors__________________________________________________

		std::string get_name() const;
		unsigned int get_grade() const;

//______________Exceptions__________________________________________________

		GradeTooHighException
		{

		};

		GradeTooLowException
		{

		};

	private:

		std::string const	_name;
		unsigned int 		_grade;

		void promotion_grade(unsigned int grade);
		void demotion_grade(unsigned int grade);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif