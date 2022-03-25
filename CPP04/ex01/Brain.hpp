#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	virtual ~Brain();
	Brain(const Brain &other);
	Brain &operator= (const Brain &other);
};

#endif