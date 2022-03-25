#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("unknown animal") {
	std::cout << "* WrongAnimal: default constructor called *" << std::endl; 
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "* WrongAnimal: Type constructor called *" << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "* WrongAnimal Copy constructor called *" << std::endl;
	_type = other._type;
}

WrongAnimal::~WrongAnimal () {
	std::cout << "* WrongAnimal: \"" << _type << "\" destroed *" << std::endl; 
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal &other) {
	std::cout << "* WrongAnimal: Copy assignment operator called *" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

const std::string& WrongAnimal::getType() const {
	return (_type);
}

void WrongAnimal::makeSound() const {
		std::cout << "WrongAnimal: I do not know who I am" << std::endl;
}