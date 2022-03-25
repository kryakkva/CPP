#include "MateriaSource.hpp"

MateriaSource::MateriaSource () : _learn(0) {
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource () {
	for (int i = 0; i < _learn; i++) {
		delete _materia[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const & otherMateria) {
	*this = otherMateria;
}

MateriaSource & MateriaSource::operator= (MateriaSource const & otherMateria) {
	if (this != &otherMateria) {
		for (int i = 0; i < _learn; i++) {
			delete _materia[i];
		}
		_learn = otherMateria._learn;
		for (int i = 0; i < otherMateria._learn; i++){
			_materia[i] = otherMateria._materia[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia) {
		std::cout << "MateriaSource: no materia to learned" << std::endl;
		return ;
	}
	if (_learn == 4) {
		delete materia;
		std::cout << "MateriaSource: no space to learn new materia" << std::endl;
	}
	else {
		_materia[_learn++] = materia;
		std::cout << "MateriaSource: new materia \"" << _materia[_learn -1]->getType() << "\" learned" << std::endl;
	}
}

 AMateria* MateriaSource::createMateria(std::string const & type)
 {
	 for (int i = 0; i < _learn; i++) {
		 if (type == _materia[i]->getType()){
			std::cout << "MateriaSource: create new materia \"" << type << "\"" << std::endl;
			return (_materia[i]->clone());
		 }
	 }
	 std::cout << "MateriaSource: Failed to create materia \"" << type << "\"" << std::endl;
	 return (NULL);
 }

 void MateriaSource::showMateria()
 {
	 for (int i = 0; i < _learn ; i++) {
		 std::cout << _materia[i]->getType() << std::endl;
	 }
 }