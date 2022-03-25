#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria("cure")  {
	_type = other._type;
}

Cure & Cure::operator= (Cure const &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const {
	std::cout << "Cure: Cure clone" << std::endl;
	return (new Cure);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}