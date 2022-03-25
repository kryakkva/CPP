#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondtrap);
	DiamondTrap &operator= (const DiamondTrap &diamondtrap);
	virtual ~DiamondTrap();

	virtual std::string _getName(void) const;

	using ScavTrap::attack;
	void whoAmI();
};

#endif