#include "Fixed.hpp"

// * CONSTRUCTORS *

Fixed::Fixed( ) : _nVal(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(i << _fBits);
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (1 << _fBits)));
}

Fixed::~Fixed( )
{
	// std::cout << "Destructor called" << std::endl;
}


// * OVERLOAD OPERATORS *

std::ostream& operator<< (std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed& Fixed::operator= ( const Fixed &Fixed )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &Fixed)
		return (*this);
	_nVal = Fixed.getRawBits();

	return (*this);
}

// * comparison operators *

bool Fixed::operator> (Fixed const &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator< (Fixed const &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>= (Fixed const &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<= (Fixed const &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator== (Fixed const &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!= (Fixed const &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

// * arithmetic operators *

Fixed Fixed::operator+ (Fixed const &fixed) const
{
	Fixed buf(this->toFloat() + fixed.toFloat());

	return (buf);
}

Fixed Fixed::operator- (Fixed const &fixed) const
{
	Fixed buf(this->toFloat() - fixed.toFloat());

	return (buf);
}

Fixed Fixed::operator* (Fixed const &fixed)  const
{
	Fixed buf(this->toFloat() * fixed.toFloat());

	return (buf);
}

Fixed Fixed::operator/ (Fixed const &fixed) const
{
	Fixed buf(this->toFloat() / fixed.toFloat());

	return (buf);
}

// * increment/decrement *

Fixed& Fixed::operator++ ()
{
	this->setRawBits(this->getRawBits() + 1);

	return (*this);
}

Fixed& Fixed::operator-- ()
{
	this->setRawBits(this->getRawBits() - 1);

	return (*this);
}

Fixed Fixed::operator++ (int)
{
	Fixed buf(*this);

	++(*this);

	return (buf);
}

Fixed Fixed::operator-- (int)
{
	Fixed buf(*this);

	--(*this);

	return (buf);
}


// * MEMBER FUNCTIONS *

Fixed::Fixed( Fixed const &fixed )
{
	// std::cout << "Copy constructor called" << std::endl;
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

Fixed& Fixed::min (Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min (Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max (Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max (Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

