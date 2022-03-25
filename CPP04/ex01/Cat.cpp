#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "* Cat: default constructor called *" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) {
	std::cout << "* Cat: Copy constructor called *" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Cat::~Cat () {
	std::cout << "* Cat: Destructor called *" << std::endl;
	delete _brain;
}

Cat& Cat::operator= (const Cat &other) {
	std::cout << "* Cat: Copy assignment operator called *" << std::endl;
	if (this != &other) {
		_type = other._type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound() const {
		std::cout << "i think i'm cat" << std::endl;
}