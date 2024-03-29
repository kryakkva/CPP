#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &other);
	Cat &operator= (const Cat &othe);

	virtual void makeSound() const;
};

#endif