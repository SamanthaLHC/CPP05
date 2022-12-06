#include <iostream>
#include <string>

class Bureaucrat
{
	public:

		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &cpy);
		Bureaucrat &operator=( Bureaucrat const &rhs);
	 	virtual ~Bureaucrat(void);


	protected:


};

#endif