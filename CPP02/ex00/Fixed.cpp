#include "Fixed.hpp"

Fixed::Fixed() : _nVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( ) {
	std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator= ( const Fixed &Fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &Fixed)
		return (*this);
	_nVal = Fixed.getRawBits();

	return (*this);
}

Fixed::Fixed( Fixed const &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return(_nVal);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_nVal = raw;
}