#include "RobotomyRequestForm.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other), _target(other._target) { }

RobotomyRequestForm & RobotomyRequestForm::operator= (RobotomyRequestForm const &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { }

std::string const & RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw OtherFormException("Form not signed!");
	if (executor.getGrade() > getGradeToExe())
		throw GradeTooLowException("Grade to execute to low!");
	std::cout << "~~~~ZzzzzzbbbrbzzzzzzzzzZZZZhhhzhzhzhz~~~~~\n";
	if (rand() % 2)
		std::cout << GREEN << getTarget() << " has been robotomized" RESET << std::endl;
	else
		std::cout << RED << getTarget() << " robotomy failed" RESET << std::endl;
}