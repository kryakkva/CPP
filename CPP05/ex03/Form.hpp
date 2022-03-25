#ifndef FORM_HPP
# define FORM_HPP

class Form;
# include "Bureaucrat.hpp"

class Form
{
private:
	std::string const _name;
	bool _sign;
	int const _gradeToSign;
	int const _gradeToExe;
public:
	Form(std::string const &name, int gradeToSign, int gradeToExe);
	Form(Form const &other);
	Form &operator= (Form const & other);
	virtual ~Form();

	std::string getName() const;
	bool getSign() const;
	int getGradeToSign() const;
	int getGradeToExe() const;

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
		virtual ~GradeTooLowException() throw();
		virtual const char* what() const throw();
	};

	class OtherFormException : public std::exception
	{
	private:
		std::string _err;
	public:
		OtherFormException(std::string err);
		virtual ~OtherFormException() throw();
		virtual const char* what() const throw();
	};

	virtual void beSigned(Bureaucrat & bur);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<< (std::ostream &out, Form const & form);

#endif