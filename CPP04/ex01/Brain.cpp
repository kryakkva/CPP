#include "Brain.hpp"

Brain::Brain() {
	std::cout << "* Brain: default constructor called *" << std::endl; 
	for (int i = 0; i < 100; i++)
		_ideas[i] = "No Idea";
}

Brain::Brain(const Brain &other) {
	std::cout << "* Brain: Copy constructor called *" << std::endl;
	for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
}

Brain::~Brain () {
	std::cout << "* Brain destroed *" << std::endl;
}

Brain& Brain::operator= (const Brain &other) {
	std::cout << "* Brain: Copy assignment operator called *" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}