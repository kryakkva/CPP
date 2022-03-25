#include "Character.hpp"

Character::Character() : _num(0) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	std::cout << "Character: Default constructor" << std::endl;
}

Character::Character(std::string const & name) : _name(name), _num(0) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	std::cout << "Character: \"" << _name << "\" Named constructor" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < _num; i++) {
		delete _inventory[i];
	}
	std::cout << "Character: Default \"" << _name << "\" destructor" << std::endl;
}

Character::Character(Character const & other) {
	*this = other;
	std::cout << "Character: Default copy constructor" << std::endl;
}

Character & Character::operator= (Character const & other)
{
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < _num; i++) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		_num = other._num;
		for (int i = 0; i < _num; i++) {
			_inventory[i] = other._inventory[i]->clone();
		}
	}
	std::cout << "Character: Assignation operator" << std::endl;
	return (*this);
}

std::string const & Character::getName() const {return (_name);}

void Character::equip(AMateria* m)
{
	if (!m) {
		std::cout << "Character: \"" << _name << "\" Invalid equip" << std::endl;
		return;
	}
	if (_num < 4) {
		_inventory[_num++] = m;
		std::cout << "Character: \"" << _name << "\" \"" << _inventory[_num - 1]->getType() << "\" equipped" << std::endl;
	}
	else
		delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > _num || !_inventory[idx]) 
		std::cout << "Character: \"" << _name << "\" nothing to unequip" << std::endl;
	else {
		std::cout << "Character: \"" << _name << "\" \"" << _inventory[idx]->getType() << "\" unequip" << std::endl;
		delete _inventory[idx];
		while (idx < 3 && _inventory[idx + 1]) {
			_inventory[idx] = _inventory[idx + 1];
			_inventory[++idx] = NULL;
		}
		_inventory[idx] = NULL;
		_num--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > _num || !_inventory[idx]) 
		std::cout << "Character: nothing to use" << std::endl;
	else {
		_inventory[idx]->use(target);
	}
}
