#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria::~AMateria() {}

AMateria::AMateria(AMateria const & otherMateria) {
	_type = otherMateria._type;
}

AMateria & AMateria::operator= (AMateria const & otherMateria) {
	if (this != &otherMateria) {
		_type = otherMateria._type;
	}
	return (*this);
}

void AMateria::use(ICharacter & target) {
	(void)target;
}

std::string const & AMateria::getType() const {
	return (_type);
}


