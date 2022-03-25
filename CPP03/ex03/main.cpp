#include "DiamondTrap.hpp"

int main( void )
{
	ClapTrap lol ("Lol");
	ClapTrap kek ("Kek");
	ScavTrap che ("Che");
	FragTrap burek ("Burek");
	DiamondTrap wtf ("WTF");


	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl;
	std::cout << wtf << std::endl << std::endl;

	wtf.attack("lol");
	wtf.guardGate();
	wtf.highFivesGuys();
	std::cout << std::endl;

	for (size_t i = 0; i < 2; i++)
	{
		lol.attack("kek");
		kek.takeDamage(lol._getAttack());
		che.attack("kek");
		kek.takeDamage(che._getAttack());
	}

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl;
	std::cout << wtf << std::endl << std::endl;

	kek.beRepaired(1);

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl;
	std::cout << wtf << std::endl << std::endl;

	che.guardGate();
	burek.highFivesGuys();
	burek.attack("Che");
	che.takeDamage(burek._getAttack());

	std::cout << std::endl << lol << std::endl;
	std::cout << kek << std::endl;
	std::cout << che << std::endl;
	std::cout << burek << std::endl;
	std::cout << wtf << std::endl << std::endl;

	return 0;
}
