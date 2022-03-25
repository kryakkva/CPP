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
	~Form();

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

	void beSigned(Bureaucrat & bur);
};

std::ostream &operator<< (std::ostream &out, Form const & form);

#endif