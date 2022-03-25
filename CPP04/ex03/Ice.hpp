#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &other);
	Ice &operator= (Ice const &other);
	~Ice();

	virtual void use(ICharacter& target);
	virtual AMateria* clone() const;
};

#endif