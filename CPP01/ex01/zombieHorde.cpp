#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name )
{
	std::string newName;
	std::stringstream ss;

	Zombie *heapZombie = new Zombie[N];
	for (size_t i = 0; i < N; i++)
	{
		ss << name + "#" << i + 1;
		ss >> newName;
		ss.clear();
		// newName = name + "#" + std::to_string(i + 1);
		heapZombie[i].setName(newName);
	}
	return (heapZombie);
}