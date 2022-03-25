#include "Bureaucrat.hpp"

#define RED "\033[0;31m"
#define ITALIC "\033[3;33m"
#define RESET "\033[0m"

void ft_title(std::string str, char c)
{
	std::cout << c << ITALIC "------ " << str << " ------\n" RESET;
}

int main() {
	Bureaucrat lol("Lol", 50);
	Form f_general("General", 100, 10);
	Form f_classified("Classified", 20, 5);
	Form forms[2] = {f_general, f_classified};

	//Instances information
	ft_title("Instances Info", '\n');
	std::cout << lol << std::endl;
	std::cout << f_general << std::endl;
	std::cout << f_classified << std::endl;

	//Form signing Lol
	ft_title("Form Signing Lol", '\n');
	for (int i = 0; i < 2; i++)
	{
		try
		{
			lol.signForm(forms[i]);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}
	}

	//Form Information
	ft_title("Form Info", '\n');
	for (int i = 0; i < 2; i++)
		std::cout << forms[i] << std::endl;

	//Form signing Kek
	ft_title("Form Signing Kek", '\n');
	Bureaucrat kek ("Kek", 19);
	kek.signForm(forms[1]);

	//Form Information
	ft_title("Form Info", '\n');
	for (int i = 0; i < 2; i++)
		std::cout << forms[i] << std::endl;

	//Instantiate unusable form
	ft_title("Instantiate unusable form", '\n');
	try
	{
		Form f_wrong1("Wrong", 100, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << e.what() << '\n' << RESET;
	}
	try
	{
		Form f_wrong2("Wrong", 151, 20);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED  << e.what() << '\n' << RESET;
	}
	std::cout << "\n";
	return 0;
}