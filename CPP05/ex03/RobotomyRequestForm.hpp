#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator= (RobotomyRequestForm const &other);
	virtual ~RobotomyRequestForm();

	std::string const &getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

#endif