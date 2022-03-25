#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "* FragTrap default constructor called! *" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "* FragTrap " << _getName() << " constructor called! *" << std::endl;
	_setHit(100);
	_setEnergy(100);
	_setAttack(30);
}

FragTrap::FragTrap(const FragTrap &scavtrap){
	*this = scavtrap;
}

FragTrap::~FragTrap () {
	std::cout << "* FragTrap " << _getName() << " destroed *" << std::endl; 
}

FragTrap& FragTrap::operator= (const FragTrap &scavtrap){
	if (this != &scavtrap) {
		_setName(scavtrap._getName());
		_setHit(scavtrap._getHit());
		_setEnergy(scavtrap._getEnergy());
		_setAttack(scavtrap._getAttack());
	}
	return (*this);
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _getName() << " said: High fives guys :)" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_getEnergy() && _getHit()) {
		_setEnergy(_getEnergy() - 1);
		std::cout << "FragTrap " << _getName() << " attacks " << target << ", causing " << _getAttack() << " points of damage!" << std::endl;
		return ;
	}
	if (!_getHit())
		std::cout << "FragTrap " << _getName() << " cannot attack " << target << ", " << _getName() << "is dead!" << std::endl;
	else
		std::cout << "FragTrap " << _getName() << " cannot attack " << target << ", not enough energy !" << std::endl;
}
