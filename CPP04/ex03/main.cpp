#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "---------- CREATING MATERIA SOURCES ----------\n";
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << "\n---------- CREATING CHARACTERS ----------\n";
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("Bob");

	std::cout << "\n---------- EQUIPPING MATERIAS ----------\n";
	AMateria *tmp;
	tmp = src->createMateria("fire");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n---------- USING MATERIAS----------\n";
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << "\n---------- UNEQUIPPING MATERIAS----------\n";
	me->unequip(0);
	me->unequip(1);
	me->unequip(1);
	me->unequip(0);
	me->unequip(-1);

	std::cout << "\n---------- DEEP COPY TEST ----------\n";
	Character *lol = new Character("Lol");
	Character *kek = new Character();
	tmp = src->createMateria("cure");
	lol->equip(tmp);
	*kek = *lol;
	std::cout << "Kek: ";
	kek->use(0, *bob);
	std::cout << "Lol: ";
	lol->use(0, *bob);

	tmp = src->createMateria("ice");
	std::cout << "Kek: ";
	kek->equip(tmp);

	std::cout << "Kek: ";
	kek->use(1, *bob);
	std::cout << "Lol: ";
	lol->use(1, *bob);

	std::cout << "\n---------- EXITING PROGRAM ----------\n";
	delete lol;
	delete kek;
	delete bob;
	delete me;
	delete src;

	return (0);
}