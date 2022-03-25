#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[0;31m"
#define ITALIC "\033[3;33m"
#define BOLD "\033[1;33m"
#define RESET "\033[0m"
#define BLUE "\033[0;34m"

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
		std::cerr << RED << e.what() << "\n" RESET;
	}
}

int main() {
	Bureaucrat lol("Lol", 100);
	Bureaucrat kek("Kek", 50);
	Bureaucrat cheburek("Cheburek", 5);
	ShrubberyCreationForm shrubForm("shrub_tree");
	RobotomyRequestForm roboForm("BrokenBot");
	PresidentialPardonForm pardonForm("Defendant");

	//Instances information
	ft_title("Instances Info", '\n');
	std::cout << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << cheburek << std::endl;
	std::cout << shrubForm << std::endl;
	std::cout << roboForm << std::endl;
	std::cout << pardonForm << std::endl;

	//Form signing
	ft_title("Form Signing", '\n');
	signForm(&shrubForm, &lol);
	signForm(&roboForm, &lol);
	signForm(&roboForm, &kek);
	signForm(&pardonForm, &cheburek);

	ft_title("Form Execution Result", '\n');
	std::cout << BLUE "Shrubbery ---------------\n" RESET;
	try
	{
		kek.executeForm(shrubForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << BLUE "\nRobotomy ---------------\n" RESET;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			cheburek.executeForm(roboForm);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << BLUE "\nPrez Pardon ---------------\n" RESET;
	try
	{
		cheburek.executeForm(pardonForm);
		kek.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}
	std::cout << "\n";
	return 0;
}