#include "Karen.hpp"

Karen::Karen()
{
	// std::cout << "Hi! My name is Keren.\n" << std::endl;
}

Karen::~Karen()
{
	// std::cout << "\nBye." << std::endl;
}

void Karen::_debug( void )
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my";
	std::cout << " 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void Karen::_info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void Karen::_warning( void )
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years whereas you started working";
	std::cout << " here since last month." << std::endl;
}

void Karen::_error( void )
{
	std::cout << "[ ERROR ]\nThis is unacceptable!";
	std::cout << " I want to speak to the manager now." << std::endl;
}

void    Karen::complain( std::string complaint )
{
	int level = -1;

	std::string levelMass[ ] = {
		std::string("DEBUG"),
		std::string("INFO"),
		std::string("WARNING"),
		std::string("ERROR")
		};

	for (size_t i = 0; i < 4; i++)
		if (complaint == levelMass[i])
			level = i;
	switch (level)
	{
	case DEBUG:
		this->_debug();
		std::cout << std::endl;
	case INFO:
		this->_info();
		std::cout << std::endl;
	case WARNING:
		this->_warning();
		std::cout << std::endl;
	case ERROR:
		this->_error();
		std::cout << std::endl;
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}
}