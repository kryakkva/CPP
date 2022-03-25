#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 72, 45), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other), _target(other._target) {}

PresidentialPardonForm & PresidentialPardonForm::operator= (PresidentialPardonForm const &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { }

std::string const & PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw OtherFormException("Form not signed!");
	if (executor.getGrade() > getGradeToExe())
		throw GradeTooLowException("Grade to execute to low!");
	std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox\n";
}