#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{	
	randomChump("Lol");
	randomChump("Kek");
	Zombie *heapZombie1 = newZombie("Che");
	Zombie *heapZombie2 = newZombie("Burek");
	heapZombie1->announce();
	heapZombie2->announce();
	delete heapZombie1;
	delete heapZombie2;
	return (0);
}