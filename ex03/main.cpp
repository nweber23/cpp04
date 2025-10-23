#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	ICharacter* hero = new Character("Cloud");
	ICharacter* enemy = new Character("Sephiroth");

	hero->equip(new Ice());
	hero->equip(new Cure());
	hero->equip(new Ice());
	hero->equip(new Cure());
	hero->equip(new Ice());

	hero->use(0, *enemy);
	hero->use(1, *enemy);
	hero->use(2, *enemy);
	hero->use(3, *enemy);
	hero->use(4, *enemy);
	hero->use(-1, *enemy);

	hero->unequip(0);
	hero->use(0, *enemy);
	hero->unequip(0);
	hero->unequip(10);

	delete hero;
	delete enemy;

	Character* original = new Character("Zidane");
	original->equip(new Ice());
	original->equip(new Cure());

	Character* copy = new Character(*original);
	ICharacter* target = new Character("Garland");

	original->use(0, *target);
	copy->use(0, *target);

	original->unequip(0);
	copy->use(0, *target);

	delete original;
	delete copy;
	delete target;

	MateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());

	AMateria* ice = src2->createMateria("ice");

	delete ice;
	delete src2;

	Character::cleanDropped();

	return 0;
}