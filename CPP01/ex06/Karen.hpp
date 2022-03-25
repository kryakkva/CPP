#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

enum levels {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Karen
{
private:
	void _debug( void );
	void _info( void );
	void _warning( void );
	void _error( void );
public:
	Karen();
	~Karen();
	void    complain( std::string complaint );
};

#endif