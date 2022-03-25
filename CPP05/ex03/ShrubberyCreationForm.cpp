#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other), _target(other._target) { }

ShrubberyCreationForm & ShrubberyCreationForm::operator= (ShrubberyCreationForm const &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

std::string const & ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw OtherFormException("Form not signed!");
	if (executor.getGrade() > getGradeToExe())
		throw GradeTooLowException("Grade to execute to low!");
	std::ofstream file;
	file.open(getTarget() + "_shrubbery", std::ios::trunc);
	if (!file)
		throw OtherFormException("Open ERROR!");
	std::string tree =	"     .{{'}}}}}}.\n"
						"    {{{{{{(')}}}.\n"
						"   {{{(')}}}}}}}}}\n"
						"  }}}}}}}}}{{('){{{\n"
						"  }}}}{{{{(')}}{{{{\n"
						" {{{(')}}}}}}}{}}}}}\n"
						"{{{{{{{{(')}}}}}}}}}}\n"
						"{{{{{{{}{{{{(')}}}}}}\n"
						" {{{{{(')   {{{{(')}'\n"
						"  ''''''|   |''''''\n"
						"        |   |\n"
						"  (')  /     \\\n"
						" ~~~~~~~~~~~~~~~~~~~";
	file << tree;
	file.close();
}
