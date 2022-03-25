#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap lol ("Lol");
	ClapTrap kek ("Kek");

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl << std::endl;

	for (size_t i = 0; i < 9; i++)
	{
		lol.attack("kek");
		kek.takeDamage(lol._getAttack());
		kek.beRepaired(1);
	}
	
	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl << std::endl;

	lol.attack("kek");
	kek.takeDamage(15);
	
	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl << std::endl;

	lol.beRepaired(20);
	lol.attack("kek");
	
	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl << std::endl;

	kek.attack("lol");
	lol.takeDamage(15);
	
	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl << std::endl;
	
	lol.beRepaired(20);
	lol.attack("kek");
	
	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl << std::endl;

	return 0;
}
