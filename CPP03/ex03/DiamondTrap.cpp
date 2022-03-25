#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	std::cout << "* DiamondTrap default constructor called *" << std::endl;
	_setHit(100);
	_setEnergy(50);
	_setAttack(30);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "* DiamondTrap " << _getName() << " constructor called *" << std::endl;
	_setHit(100);
	_setEnergy(50);
	_setAttack(30);
}

std::string DiamondTrap::_getName() const {
	return (_name);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "* DiamondTrap " << _getName() << " destroed *" << std::endl; 
}

void DiamondTrap::whoAmI() {
	std::cout << "* DiamondTrap: my name is " << _getName() << " *" << std::endl; 
	std::cout << "* DiamondTrap: my parent name is " << ClapTrap::_getName() << " *" << std::endl; 
}