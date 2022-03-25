#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const & other);
	Bureaucrat const &operator= (Bureaucrat const & other);
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
	private:
		std::string _err;
	public:
		GradeTooHighException(std::string err);
		virtual ~GradeTooHighException() throw();
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		std::string _err;
	public:
		GradeTooLowException(std::string err);
		virtual ~GradeTooLowException() throw() ;
		virtual const char* what() const throw();
	};

	std::string const & getName() const;
	int getGrade() const;
	
	void increment();
	void decrement();

	void signForm(Form &form);
	void executeForm(Form const &form) const;
};

std::ostream &operator<< (std::ostream& out, Bureaucrat const & bur);

#endif