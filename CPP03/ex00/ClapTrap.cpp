#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "* ClapTrap default constructor called *" << std::endl; 
}

ClapTrap::ClapTrap(std::string name) : _name(name) , _hit(10), _energy(10) , _attack(0) {
	std::cout << "* ClapTrap " << _getName() << " constructor called *" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "* ClapTrap Copy constructor called *" << std::endl;
	*this = claptrap;
}

ClapTrap::~ClapTrap () {
	std::cout << "* ClapTrap " << _name << " destroed *" << std::endl; 
}

ClapTrap& ClapTrap::operator= (const ClapTrap &claptrap) {
	std::cout << "* ClapTrap Copy assignment operator called *" << std::endl;
	if (this == &claptrap)
		return (*this);
	_name = claptrap._name;
	_hit = claptrap._hit;
	_energy = claptrap._energy;
	_attack = claptrap._attack;
	return (*this);
}


// * GETTERS *

std::string ClapTrap::_getName() const { return (_name); }
unsigned int ClapTrap::_getHit() const { return (_hit); }
unsigned int ClapTrap::_getAttack() const { return (_attack); }
unsigned int ClapTrap::_getEnergy() const { return (_energy); }


// * SETTERS *

void ClapTrap::_setName(std::string name) { _name = name; }
void ClapTrap::_setHit(unsigned int hit) { _hit = hit; }
void ClapTrap::_setAttack(unsigned int attack) { _attack = attack; }
void ClapTrap::_setEnergy(unsigned int energy) { _energy = energy; }


// * METHODS *	

void ClapTrap::attack(const std::string& target)
{
	if (_energy && _hit) {
		_energy--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
	}
	else
	{
		if (!_hit)
			std::cout << "ClapTrap " << _name << " cannot attack " << target << ", " << _name << " is dead!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " cannot attack " << target << ", not enough energy !" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit) {
		std::cout << _name << " take damage by " << amount << " points!" << std::endl;
		if (_hit >= amount)
			_hit -= amount;
		else {
			std::cout << _name << " is dead" << std::endl;
			_hit = 0;
		}
	}
	else
		std::cout << _name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy && _hit) {
		_energy--;
		_hit += amount;
		std::cout << _name << " repaired itself by " << amount << " points!" << std::endl;
	}
	else {
		if (!_hit)
			std::cout << _name << " cannot repair itself, " << _name << " is dead" << std::endl;
		else
			std::cout << _name << " cannot repair itself, not enough energy!" << std::endl;
	}
}

std::ostream& operator<< (std::ostream &out, const ClapTrap &claptrap)
{
	out << claptrap._getName();
	out << ":	HIT = " << claptrap._getHit();
	out << ",	ENERGY = " << claptrap._getEnergy();
	out << ",	ATTACK = " << claptrap._getAttack();
	return (out);
}