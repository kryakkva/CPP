#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &otherDog);
	Dog &operator= (const Dog &otherDog);

	virtual void makeSound() const;
};

#endif