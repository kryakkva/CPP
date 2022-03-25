#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator= (Intern const &other);
	~Intern();

	class internException : public std::exception
	{
	private:
		std::string _err;
	public:
		internException(std::string err);
		virtual ~internException() throw();
		virtual const char* what() const throw();
	};

	Form *makeForm(std::string form, std::string name);
};

#endif