#include "Karen.hpp"

typedef void (Karen::*functPtr)();

Karen::Karen()
{
	std::cout << "Hi! My name is Keren.\n" << std::endl;
}

Karen::~Karen()
{
	std::cout << "\nBye." << std::endl;
}

void Karen::_debug( void )
{
	std::cout << "I love having extra bacon for my";
	std::cout << " 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void Karen::_info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void Karen::_warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years whereas you started working";
	std::cout << " here since last month." << std::endl;
}

void Karen::_error( void )
{
	std::cout << "This is unacceptable!";
	std::cout << " I want to speak to the manager now." << std::endl;
}

void    Karen::complain( std::string level )
{
	std::string levelMass[ ] = {
		std::string("DEBUG"),
		std::string("INFO"),
		std::string("WARNING"),
		std::string("ERROR")
		};
	functPtr functMass[ ] = {
		&Karen::_debug,
		&Karen::_info,
		&Karen::_warning,
		&Karen::_error
	};

	for (size_t i = 0; i < 4; i++)
		if (level == levelMass[i])
			(this->*functMass[i])();
}