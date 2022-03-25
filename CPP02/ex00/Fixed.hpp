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
	~Fixed();
	Fixed(const Fixed &Fixed);
	Fixed &operator= (Fixed const &Fixed);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
