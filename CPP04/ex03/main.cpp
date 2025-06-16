/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:31 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:32 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "color.h"

#include <iostream>

void basicmain();
void othertests();
void nomateriasource();
void withmateriasource();

int main() {
	std::string input;
	while (1) {
		std::cout << GREEN << "Choose your test :" << RESET << std::endl;
		std::cout << "- 1: Basic main\n- 2: Other tests\n- 3: Test with no materia source and copied\n- 4: test with materia source and copies\n- 5: exit\nEnter your choice: ";
		std::getline(std::cin, input);
		if (input == "5" || std::cin.eof())
			break;
		else if (input == "1")
			basicmain();
		else if (input == "2")
			othertests();
		else if (input == "3")
			nomateriasource();
		else if (input == "4")
			withmateriasource();
		else
			std::cout << RED << "Invalid input" << RESET;
		std::cout << "\n" << std::endl;
	}
	return 0;
}

void basicmain() {
	std::cout << YELLOW << "-------- BASIC MAIN --------\n" << RESET << std::endl;

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
}

void othertests() {
	std::cout << YELLOW << "\n-------- OTHER TESTS --------\n" << RESET << std::endl;
	std::cout << BLUE << "-------- learn materia --------\n" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << BLUE << "\n-------- equip first materia and use it --------\n" << RESET << std::endl;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);

	std::cout << BLUE << "\n-------- try to use others --------\n" << RESET << std::endl;
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(13, *bob);
	me->use(-3, *bob);

	std::cout << BLUE << "\n-------- equip full --------\n" << RESET << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(1, *bob);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << BLUE << "\n-------- unequip then equip --------\n" << RESET << std::endl;
	me->unequip(1);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << BLUE << "\n-------- unequip everything --------\n" << RESET << std::endl;
	me->unequip(0);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	delete me;
	delete src;
	delete bob;
}

void nomateriasource() {
	std::cout << YELLOW << "\n-------- TESTS WITH NO MATERIA SOURCE --------\n" << RESET << std::endl;
	Character gollum("Gollum");
	Character frodo("Frodo");
	AMateria* tmp;
	AMateria* tmp2;
	tmp = new Ice();

	std::cout << BLUE << "-------- Equip twice same materia --------\n" << RESET << std::endl;
	gollum.equip(tmp);
	gollum.equip(tmp);


	std::cout << BLUE << "\n-------- Equip all materias --------\n" << RESET << std::endl;
	tmp = new Ice();
	gollum.equip(tmp);
	tmp = new Cure();
	gollum.equip(tmp);
	tmp2 = new Cure();
	gollum.equip(tmp2);
	tmp = new Cure();
	gollum.equip(tmp);

	std::cout << BLUE << "\n-------- Unequip and try to reequip previous materia with full inventory --------\n" << RESET << std::endl;
	gollum.unequip(3);
	tmp = new Cure();
	gollum.equip(tmp);
	gollum.equip(tmp2);
	std::cout << BLUE << "\n-------- copies --------\n" << RESET << std::endl;
	Character copy(frodo);
	frodo.use(0, gollum);
	frodo = gollum;
	frodo.use(0, gollum);
	frodo.use(2, gollum);
	copy.use(0, gollum);
	copy.use(2, gollum);
}

void withmateriasource() {
	std::cout << YELLOW << "\n-------- TESTS WITH MATERIA SOURCE --------" << RESET << std::endl;
	std::cout << BLUE << "\n-------- copies --------\n" << RESET << std::endl;
	Character me("Loulou");
	Character enemy("Enemy");
	MateriaSource src;
	src.learnMateria(new Ice());
	MateriaSource copy(src);
	AMateria* tmp;
	tmp = copy.createMateria("ice");
	me.equip(tmp);
	me.use(0, enemy);
	src.learnMateria(new Cure());
	tmp = copy.createMateria("cure");
	MateriaSource copy2;
	copy2 = src;
	tmp = copy2.createMateria("cure");
	me.equip(tmp);
	me.use(1, enemy);
}
