#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap lol ("Lol");
	ClapTrap kek ("Kek");
	ScavTrap che ("Che");
	ScavTrap burek ("Burek");

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl << std::endl;

	for (size_t i = 0; i < 2; i++)
	{
		lol.attack("kek");
		kek.takeDamage(lol._getAttack());
		che.attack("lol");
		lol.takeDamage(che._getAttack());
	}

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl << std::endl;

	kek.beRepaired(1);
	lol.beRepaired(1);

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl << std::endl;

	burek.guardGate();
	burek.attack("Che");
	che.takeDamage(burek._getAttack());

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl << std::endl;

	return 0;
}
