#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "* Dog: default constructor called *" << std::endl; 
}

Dog::Dog(const Dog &other) {
	std::cout << "* Dog: Copy constructor called *" << std::endl;
	_type = other._type;
}

Dog::~Dog () {
	std::cout << "* Dog: \"" << _type << "\" destroed *" << std::endl;
}

Dog& Dog::operator= (const Dog &other) {
	std::cout << "* Dog: Copy assignment operator called *" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void Dog::makeSound() const {
		std::cout << "i think i'm dog" << std::endl;
}