#include "Animal.hpp"

Animal::Animal() : _type("unknown animal") {
	std::cout << "* Animal: default constructor called *" << std::endl; 
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "* Animal: Type constructor called *" << std::endl; 
}

Animal::Animal(const Animal &other) {
	std::cout << "* Animal Copy constructor called *" << std::endl;
	_type = other._type;
}

Animal::~Animal () {
	std::cout << "* Animal: \"" << _type << "\" destroed *" << std::endl; 
}

Animal& Animal::operator= (const Animal &other) {
	std::cout << "* Animal: Copy assignment operator called *" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

const std::string& Animal::getType() const {
	return (_type);
}

void Animal::makeSound() const {
		std::cout << "I do not know who I am" << std::endl;
}