#include "Dog.hpp"
#include "Cat.hpp"

#define SIZE 6

int main(void)
{
	int i;
	Animal *animals[SIZE];
	
	for (i = 0; i < SIZE; i++) {
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;

	for (int j = 0; j < SIZE; j++) {
		animals[j]->makeSound();
	}
	
	std::cout << std::endl;

	for (i = 0; i < SIZE; i++)
		delete animals[i];
	return (0);
}	