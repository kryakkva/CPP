#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "* WrongCat: default constructor called *" << std::endl; 
}

WrongCat::WrongCat(const WrongCat &other) {
	std::cout << "* WrongCat: Copy constructor called *" << std::endl;
	_type = other._type;
}

WrongCat::~WrongCat () {
	std::cout << "* WrongCat: \"" << _type << "\" destroed *" << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat &other) {
	std::cout << "* WrongCat: Copy assignment operator called *" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

void WrongCat::makeSound() const {
		std::cout << "i think i'm cat" << std::endl;
}