#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (std::string const name, int grade) : _name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("for a bureaucrat " + _name + " grade " + 
			std::to_string(grade) + " is too Low!");
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("for a bureaucrat " + _name + " grade " + 
			std::to_string(grade) + " is too High!");
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & other) {
	_grade = other.getGrade();
}

Bureaucrat const & Bureaucrat::operator= (Bureaucrat const & other) {
	if (this != &other) {
		_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat () {}

std::string const & Bureaucrat::getName() const {return (_name);}
int Bureaucrat::getGrade() const {return (_grade);}

void Bureaucrat::increment() {
	if (_grade <= 1) {
		std::cerr << "for a bureaucrat " << _name;
		throw Bureaucrat::GradeTooHighException(" grade is too High!");
	}
	_grade--;
}

void Bureaucrat::decrement() {
	if (_grade >= 150) {
		std::cerr << "for a bureaucrat " << _name;
		throw Bureaucrat::GradeTooLowException(" grade is too Low!");
	}
	_grade++;
}

std::ostream &operator<< (std::ostream& out, Bureaucrat const & bur) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}

void Bureaucrat::signForm(Form &form)
{
	if (getGrade() <= form.getGradeToSign())
		std::cout << getName() + " signed " + form.getName() << std::endl;
	else
		std::cerr << getName() + " couldn't sign " + form.getName() + " because ";
	form.beSigned(*this);
}

void Bureaucrat::executeForm(Form const &form) const
{
	if (getGrade() <= form.getGradeToExe() && form.getSign())
		std::cout << getName() + " executed " + form.getName() << std::endl;
	else
		std::cerr << getName() + " couldn't executed " + form.getName() + " because ";
	form.execute(*this);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string err) : _err(err) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() { return _err.c_str(); }

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string err) : _err(err) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() { return _err.c_str(); }