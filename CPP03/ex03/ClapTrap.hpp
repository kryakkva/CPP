#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hit;
	unsigned int _energy;
	unsigned int _attack;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap &operator= (const ClapTrap &claptrap);
	virtual ~ClapTrap();

// * GETTERS *	
	virtual std::string _getName(void) const;
	unsigned int _getHit(void) const;
	unsigned int _getAttack(void) const;
	unsigned int _getEnergy(void) const;

// * SETTERS *	
	void _setName(std::string name);
	void _setHit(unsigned int hit);
	void _setAttack(unsigned int attack);
	void _setEnergy(unsigned int energy);

// * METHODS *	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

std::ostream& operator<< (std::ostream &out, const ClapTrap &claptrap);

#endif
