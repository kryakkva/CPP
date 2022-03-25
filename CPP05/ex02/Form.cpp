#include "Form.hpp"

Form::Form(std::string const &name, int gradeToSign, int gradeToExe) : 
							_name(name),
							_sign(false),
							_gradeToSign(gradeToSign),
							_gradeToExe(gradeToExe)
{
	if (_gradeToSign < 1 || _gradeToExe < 1)
		throw Form::GradeTooHighException("Grade to sign or Grade to execute to high!");
	if (_gradeToSign > 150 || _gradeToExe > 150)
		throw Form::GradeTooLowException("Grade to sign or Grade to execute to low!");		
}

Form::Form(Form const & other) : 
							_name(other.getName()),
							_sign(other.getSign()),
							_gradeToSign(other.getGradeToSign()),
							_gradeToExe(other.getGradeToExe()) {}

Form & Form::operator=(Form const &other)
{
	if (this != &other)
		_sign = other.getSign();
	return (*this);
}

Form::~Form () {};

std::string Form::getName() const { return _name; }
bool Form::getSign() const { return _sign; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExe() const { return _gradeToExe; }

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > getGradeToSign())
	{
		throw Form::GradeTooLowException("grade to sign to low!");
	}
	else
	{
		_sign = true;
	}
}

std::ostream &operator<< (std::ostream &out, Form const & form)
{
	out << "Form:\t" << form.getName() <<  ";\n\tgrade for sign: " << form.getGradeToSign()
	<< ";\n\tgrade for execute: " << form.getGradeToExe();
	if (form.getSign())
		out << ";\n\tstatus: signed";
	else
		out << ";\n\tstatus: not signed";
	return out;
}

Form::GradeTooHighException::GradeTooHighException(std::string err) : _err(err) {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Form::GradeTooHighException::GradeTooHighException::what() const throw() { return _err.c_str(); }

Form::GradeTooLowException::GradeTooLowException(std::string err) : _err(err) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Form::GradeTooLowException::GradeTooLowException::what() const throw() { return _err.c_str(); }

Form::OtherFormException::OtherFormException(std::string err) : _err(err) {}
Form::OtherFormException::~OtherFormException() throw() {}
const char* Form::OtherFormException::OtherFormException::what() const throw() { return _err.c_str(); }