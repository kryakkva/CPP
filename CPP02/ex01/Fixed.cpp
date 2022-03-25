#include "Fixed.hpp"

Fixed::Fixed( ) : _nVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i << _fBits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (1 << _fBits)));
}

Fixed::~Fixed( )
{
	std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator= ( const Fixed &Fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &Fixed)
		return (*this);
	_nVal = Fixed.getRawBits();

	return (*this);
}

Fixed::Fixed( Fixed const &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

int Fixed::getRawBits( void ) const
{
	return(_nVal);
}

void Fixed::setRawBits( int const raw )
{
	_nVal = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)_nVal / (float)(1 << _fBits));
}

int Fixed::toInt( void ) const
{
	return (_nVal >> _fBits);
}

std::ostream& operator<< (std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}