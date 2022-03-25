#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap &operator= (const ScavTrap &scavtrap);
	virtual ~ScavTrap();

	void guardGate();
	void attack(const std::string& target);
};

#endif