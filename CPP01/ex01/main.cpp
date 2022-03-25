#include "Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name);

int main(void)
{
	int num;

	num = 12;
	Zombie *horde = zombieHorde(num, "Lol");
	for (size_t i = 0; i < num; i++)
		horde[i].announce();
	delete[] horde;
	horde = nullptr;
	return (0);
}