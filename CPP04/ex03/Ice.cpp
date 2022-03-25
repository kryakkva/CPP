#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &other) : AMateria("ice") {
	_type = other._type;
}

Ice & Ice::operator= (Ice const &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
	std::cout << "Ice: Ice clone" << std::endl;
	return (new Ice);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}