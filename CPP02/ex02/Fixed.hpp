#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _nVal;
	static const int _fBits = 8;
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();
	Fixed(const Fixed &Fixed);

	Fixed& operator= (Fixed const &fixed);
	bool operator> (Fixed const &fixed) const;
	bool operator< (Fixed const &fixed) const;
	bool operator>= (Fixed const &fixed) const;
	bool operator<= (Fixed const &fixed) const;
	bool operator== (Fixed const &fixed) const;
	bool operator!= (Fixed const &fixed) const;

	Fixed operator+ (Fixed const &fixed) const;
	Fixed operator- (Fixed const &fixed) const;
	Fixed operator* (Fixed const &fixed) const;
	Fixed operator/ (Fixed const &fixed) const;
	
	Fixed& operator++ ();
	Fixed& operator-- ();
	Fixed operator++ (int);
	Fixed operator-- (int);

	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	static Fixed& min (Fixed &a, Fixed &b);
	static const Fixed& min (Fixed const &a, Fixed const &b);
	static Fixed& max (Fixed &a, Fixed &b);
	static const Fixed& max (Fixed const &a, Fixed const &b);
};

std::ostream &operator<< (std::ostream &out, Fixed const &fixed);

#endif
