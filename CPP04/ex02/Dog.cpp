#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	_brain = new Brain();
	std::cout << "* Dog: default constructor called *" << std::endl; 
}

Dog::Dog(const Dog &other) {
	std::cout << "* Dog: Copy constructor called *" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Dog::~Dog () {
	std::cout << "* Dog: Dstructor called *" << std::endl;
	delete _brain;
}

Dog& Dog::operator= (const Dog &other) {
	std::cout << "* Dog: Copy assignment operator called *" << std::endl;
	if (this != &other) {
		_type = other._type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Dog::makeSound() const {
		std::cout << "i think i'm dog" << std::endl;
}
