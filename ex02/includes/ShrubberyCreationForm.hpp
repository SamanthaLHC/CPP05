#ifndef SHRUBBERYCREATIONShrubberyCreationForm_HPP
#define SHRUBBERYCREATIONShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
public:
	//______________Constructors an destructor_________________________________

	ShrubberyCreationForm(std::string name, unsigned int grade_sign, unsigned int grade_exec);
	ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
	~ShrubberyCreationForm(void);

	//______________Operator overload___________________________________________

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	//______________Accessors__________________________________________________

	std::string get_name() const;
	unsigned int get_grade_to_sign() const;
	unsigned int get_grade_to_exec() const;
	bool get_signed_status() const;

	//______________Exceptions__________________________________________________

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

	class ShrubberyCreationFormAlreadySigned : public std::exception
	{
		const char *what() const throw();
	};

	//______________Members functions______________________________________

	void be_signed(Bureaucrat &bureaucrat);
	// Créé un fichier <target>_shrubbery dans le répertoire courant, et écrit des arbres
	// ASCII à l’intérieur.
	void create_file_and_plant_trees();

private:

	ShrubberyCreationForm(void);
	std::string const _name;
	unsigned int const _grade_to_sign;
	unsigned int const _grade_to_exec;
	bool _is_signed;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);

#endif