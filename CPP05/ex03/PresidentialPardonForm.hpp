#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator= (PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm();

	std::string const &getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

#endif