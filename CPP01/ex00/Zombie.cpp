#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie: " << this->_name << " is dead\n";
}

void Zombie::announce( void )
{
	std::cout	<< this->_name
				<< ": BraiiiiiiinnnzzzZ...\n";
}