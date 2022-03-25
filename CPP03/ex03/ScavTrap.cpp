#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "* ScavTrap default constructor called! *" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "* ScavTrap " << _getName() << " constructor called! *" << std::endl;
	_setHit(100);
	_setEnergy(50);
	_setAttack(20);
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap){
	*this = scavtrap;
}

ScavTrap::~ScavTrap () {
	std::cout << "* ScavTrap " << _getName() << " destroed *" << std::endl; 
}

ScavTrap& ScavTrap::operator= (const ScavTrap &scavtrap){
	if (this != &scavtrap) {
		_setName(scavtrap._getName());
		_setHit(scavtrap._getHit());
		_setEnergy(scavtrap._getEnergy());
		_setAttack(scavtrap._getAttack());
	}
	return (*this);
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _getName() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_getEnergy() && _getHit()) {
		_setEnergy(_getEnergy() - 1);
		std::cout << "ScavTrap " << _getName() << " attacks " << target << ", causing " << _getAttack() << " points of damage!" << std::endl;
		return ;
	}
	if (!_getHit())
		std::cout << "ScavTrap " << _getName() << " cannot attack " << target << ", " << _getName() << "is dead!" << std::endl;
	else
		std::cout << "ScavTrap " << _getName() << " cannot attack " << target << ", not enough energy !" << std::endl;
}
