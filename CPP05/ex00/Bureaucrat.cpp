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
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException("for a bureaucrat " + _name + " grade is too High!");
	_grade--;
}

void Bureaucrat::decrement() {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException("for a bureaucrat " + _name + " grade is too Low!");
	_grade++;
}

std::ostream &operator<< (std::ostream& out, Bureaucrat const & bur) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (out);
}


Bureaucrat::GradeTooHighException::GradeTooHighException(std::string err) : _err(err) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char* Bureaucrat::GradeTooHighException::what() const throw() { return _err.c_str(); }

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string err) : _err(err) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw() { return _err.c_str(); }