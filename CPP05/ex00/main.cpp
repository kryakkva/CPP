#include "Bureaucrat.hpp"

#define RED "\033[0;31m"
#define ITALIC "\033[3;33m"
#define RESET "\033[0m"

void ft_title(std::string str, char c)
{
	std::cout << c << ITALIC "------ " << str << " ------\n" RESET;
}

int main() {
	Bureaucrat lol("Lol", 3);
	Bureaucrat kek("Kek", 148);

	//Increment grade until it's too high
	ft_title("TEST 1, Increment until too high", '\n');
	for (int i = 0; i < 4; i++)
	{
		try
		{
			lol.increment();
			std::cout << lol << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << "\n" << RESET;
		}
	}

	//Decrement grade until it's too low
	ft_title("TEST 2, Decrement until too low", '\n');
	for (int i = 0; i < 4; i++)
	{
		try
		{
			kek.decrement();
			std::cout << kek << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << "\n" << RESET;
		}
	}

	//Instantiate an unusable Bureaucrat
	ft_title("TEST 3, Instantiate an unsuable Bureaucrat", '\n');
	try
	{
		Bureaucrat cheburek("Cheburek", 160);
	}
	catch (std::exception &e)
	{
		std::cerr << RED  << e.what() << "\n" << RESET;
	}
	return 0;
}