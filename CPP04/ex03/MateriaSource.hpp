#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materia[4];
	int _learn;
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(MateriaSource const & otherMateria);
	MateriaSource &operator= (MateriaSource const & otherMateria);

	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
	void showMateria();
};

#endif