#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

int main() {
	// {
	// 	std::cout << YELLOW << "MATERIA TEST:\n" << RESET << std::endl;

	// 	std::cout << YELLOW << "Default constructor:" << RESET << std::endl;
	// 	Ice ice1;
	// 	std::cout << "Type: " << ice1.getType() << std::endl;
	// 	Cure cure1;
	// 	std::cout << "Type: " << cure1.getType() << std::endl;

	// 	std::cout << YELLOW << "\nParameterized constructor:" << RESET << std::endl;
	// 	AMateria* ice2 = ice1.clone();
	// 	std::cout << "Cloned Type: " << ice2->getType() << std::endl;
	// 	AMateria* cure2 = cure1.clone();
	// 	std::cout << "Cloned Type: " << cure2->getType() << std::endl;

	// 	std::cout << YELLOW << "\nCopy constructor:" << RESET << std::endl;
	// 	Ice ice3(ice1);
	// 	std::cout << "Type: " << ice3.getType() << std::endl;
	// 	Cure cure3(cure1);
	// 	std::cout << "Type: " << cure3.getType() << std::endl;

	// 	std::cout << YELLOW << "\nAssignment operator:" << RESET << std::endl;
	// 	Ice ice4;
	// 	ice4 = ice1;
	// 	std::cout << "Type: " << ice4.getType() << std::endl;
	// 	Cure cure4;
	// 	cure4 = cure1;
	// 	std::cout << "Type: " << cure4.getType() << std::endl;

	// 	std::cout << YELLOW << "\nTesting destructor:" << RESET << std::endl;
	// 	delete ice2;
	// 	delete cure2;
	// }
	// {
		// IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// // src->learnMateria(new Cure());
		// // src->learnMateria(new Cure());
		// // Cure *tmp = new Cure();
		// // src->learnMateria(tmp);
		// // src->learnMateria(tmp);

		// ICharacter* me = new Character("me");
		// AMateria* tmp;
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// tmp = src->createMateria("hello");
		// me->equip(tmp);

		// ICharacter* bob = new Character("bob");
		// me->use(0, *bob);
		// me->use(1, *bob);
		// delete bob;
		// delete me;
		// delete src;
	// }
	// {
	// 	std::cout << YELLOW << "CHARACTER TEST TEST:\n" << RESET << std::endl;
	// 	ICharacter* gollum = new Character("Gollum");
	// 	ICharacter* frodo = new Character("Frodo");
	// 	AMateria* tmp;
	// 	AMateria* tmp2;
	// 	tmp = new Ice();

	// 	std::cout << YELLOW << "\nEquip twice same materia" << RESET << std::endl;
	// 	gollum->equip(tmp);
	// 	gollum->equip(tmp);

	// 	std::cout << YELLOW << "\nUse materia" << RESET << std::endl;
	// 	gollum->use(0, *frodo);
	// 	gollum->use(-10, *frodo);
	// 	gollum->use(2, *frodo);

	// 	std::cout << YELLOW << "\nEquip all materias" << RESET << std::endl;
	// 	tmp = new Ice();
	// 	gollum->equip(tmp);
	// 	tmp = new Cure();
	// 	gollum->equip(tmp);
	// 	tmp2 = new Cure();
	// 	gollum->equip(tmp2);
	// 	gollum->equip(tmp2);
	// 	tmp = new Cure();
	// 	gollum->equip(tmp);

	// 	std::cout << YELLOW << "\nUnequip" << RESET << std::endl;
	// 	gollum->unequip(2);
	// 	gollum->equip(tmp2);
	// 	gollum->unequip(2);
	// 	tmp2 = new Cure();
	// 	gollum->equip(tmp2);

	// 	std::cout << YELLOW << "\nUse" << RESET << std::endl;
	// 	gollum->use(-1, *frodo);
	// 	gollum->use(4, *frodo);
	// 	gollum->use(0, *frodo);
	// 	gollum->use(1, *frodo);
	// 	gollum->use(2, *frodo);
	// 	gollum->use(3, *frodo);
	// 	gollum->unequip(1);
	// 	gollum->use(0, *frodo);
	// 	gollum->use(1, *frodo);
	// 	gollum->use(2, *frodo);
	// 	gollum->use(3, *frodo);
	// 	gollum->unequip(0);
	// 	gollum->unequip(2);
	// 	gollum->unequip(3);
	// 	gollum->use(0, *frodo);
	// 	gollum->use(1, *frodo);
	// 	gollum->use(2, *frodo);
	// 	gollum->use(3, *frodo);

	// 	std::cout << YELLOW << "\ndestructor" << RESET << std::endl;
	// 	delete gollum;
	// 	delete frodo;
	// }
	{
		std::cout << YELLOW << "CHARACTER COPY TEST:\n" << RESET << std::endl;
		Character gollum("Gollum");
		AMateria* tmp;
		AMateria* tmp2;
		AMateria* tmp3;
		AMateria* tmp4;
		AMateria* tmp5;
		tmp = new Ice();
		tmp2 = new Ice();
		tmp3 = new Ice();
		tmp4 = new Ice();
		tmp5 = new Ice();

		std::cout << YELLOW << "\nEquip" << RESET << std::endl;
		gollum.equip(tmp);
		gollum.equip(tmp2);
		gollum.equip(tmp3);
		gollum.equip(tmp5);
		gollum.equip(tmp4);

		std::cout << YELLOW << "\nUnequip" << RESET << std::endl;
		gollum.unequip(2);
		// gollum.equip(tmp3);
		gollum.unequip(3);
		gollum.equip(tmp4);
		gollum.unequip(2);
		gollum.equip(tmp3);
		gollum.equip(tmp5);
		gollum.unequip(2);
		gollum.unequip(0);

		// gollum.equip(tmp5);

		// gollum.unequip(3);
		// gollum.equip(tmp4);
		// gollum.unequip(3);
		// gollum.equip(tmp4);
		// gollum.unequip(3);
		// gollum.equip(tmp4);
		// gollum.unequip(3);
		// gollum.equip(tmp4);
		// gollum.equip(tmp3);


		std::cout << YELLOW << "\nCopy" << RESET << std::endl;
		Character frodo("Frodo");
		Character gollumbis(gollum);
		gollumbis.printGround();
		gollum.printGround();
		frodo = gollum;
		gollum.printGround();
		frodo.printGround();
		std::cout << YELLOW << "\ndestructor" << RESET << std::endl;
	}
	return 0;
}
