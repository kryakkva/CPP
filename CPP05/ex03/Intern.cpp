#include "Intern.hpp"

Intern::Intern () {}
Intern::Intern(Intern const &other) { *this = other; }
Intern & Intern::operator= (Intern const &other) { (void)other; return *this; }
Intern::~Intern () {}

Form * Intern::makeForm(std::string form, std::string name)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;
	
	for (i = 0; i < 3; i++)
	{
		if (form == forms[i])
			break ;
		if (i == 2)
			throw internException("intern: I don't know how to create " + form + " form");
	}
	switch (i)
	{
	case 0:
	{
		std::cout << "intern create " << form << " form for " << name << std::endl;
		return new ShrubberyCreationForm(name);
	}
	case 1:
	{
		std::cout << "intern create " << form << " form for " << name << std::endl;
		return new RobotomyRequestForm(name);
	}
	case 2:
	{
		std::cout << "intern create " << form << " form for " << name << std::endl;
		return new PresidentialPardonForm(name);	
	}
	}
	return NULL;
}

Intern::internException::internException(std::string err) : _err(err) {}
Intern::internException::~internException() throw() {}
const char* Intern::internException::internException::what() const throw() { return _err.c_str(); }