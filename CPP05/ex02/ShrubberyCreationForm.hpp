#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator= (ShrubberyCreationForm const &other);
	virtual ~ShrubberyCreationForm();

	std::string const &getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

#endif