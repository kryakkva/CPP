#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "* Cat: default constructor called *" << std::endl; 
}

Cat::Cat(const Cat &other) {
	std::cout << "* Cat: Copy constructor called *" << std::endl;
	_type = other._type;
}

Cat::~Cat () {
	std::cout << "* Cat: \"" << _type << "\" destroed *" << std::endl;
}

Cat& Cat::operator= (const Cat &other) {
	std::cout << "* Cat: Copy assignment operator called *" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void Cat::makeSound() const {
		std::cout << "i think i'm cat" << std::endl;
}