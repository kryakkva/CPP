#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class AMateria;
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria(AMateria const & otherMateria);
	AMateria &operator= (AMateria const & otherMateria);
	
	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif