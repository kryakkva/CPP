#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &other);
	Cure &operator= (Cure const &other);
	virtual ~Cure();
	
	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
};

#endif