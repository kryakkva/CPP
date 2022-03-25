// #include "Bureaucrat.hpp" //class redefinition error during compilation
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <unistd.h> //for sleep()

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BOLD "\033[1;33m"
#define ITALIC "\033[3;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

void ft_title(std::string str, char c)
{
	std::cout << c << ITALIC "------ " << str << " ------\n" RESET;
}

void signForm(Form *form, Bureaucrat *bur)
{
	try
	{
		bur->signForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET;
	}
}

Form *createForm(Intern *intern, std::string const &formName, std::string const &target)
{
	Form *rrf = NULL;
	try
	{
		rrf = intern->makeForm(formName, target);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << std::endl << RESET ;
	}
	return (rrf);
}
int main()
{
	std::cout << BOLD "\n========== EX03 TESTS ==========\n" RESET;
	Bureaucrat cheburek("Cheburek", 5);
	Intern someRandomIntern;
	Form *shrub;
	Form *robo;
	Form *pardon;

	ft_title("Creating forms", '\n');
	shrub = createForm(&someRandomIntern, "Gift for me", "new phone");
	shrub = createForm(&someRandomIntern, "shrubbery creation", "home");
	robo = createForm(&someRandomIntern, "robotomy request", "borkenBot");
	pardon = createForm(&someRandomIntern, "presidential pardon", "Defendant");

	ft_title("Instances Info", '\n');
	std::cout << cheburek << std::endl;
	std::cout << *shrub << std::endl;
	std::cout << *robo << std::endl;
	std::cout << *pardon << std::endl;

	ft_title("Presidential Pardon Form Signing", '\n');
	signForm(pardon, &cheburek);

	ft_title("Presidential Pardon Form Execution", '\n');
	try
	{
		cheburek.executeForm(*pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	delete shrub;
	delete robo;
	delete pardon;
}