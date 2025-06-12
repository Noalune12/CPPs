/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:49 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:50 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int main()
{
	{
		std::cout << std::endl << "--- Source --- " << std::endl;
		DiamondTrap	Source("source");
		Source.whoAmI();
		Source.printStatus();
		std::cout << std::endl << "--- Copy --- " << std::endl;
		DiamondTrap	Copy = Source;
		Copy.whoAmI();
		Copy.printStatus();
	}
	std::cout << std::endl;
	{
		DiamondTrap	Charlie("Charlie");
		DiamondTrap	Erwan("Erwan");

		std::cout << std::endl << "---------- High Fives, Guard Gate and Who am I ----------" << std::endl << std::endl;
		Charlie.highFivesGuys();
		Erwan.highFivesGuys();
		Charlie.guardGate();
		Erwan.guardGate();
		Charlie.whoAmI();
		Erwan.whoAmI();

		std::cout << std::endl << "---------- ATTACK AND TAKE DAMAGES ----------" << std::endl << std::endl;
		Charlie.attack("Erwan");
		Erwan.attack("Charlie");
		Erwan.takeDamage(30);
		Erwan.printStatus();
		Charlie.takeDamage(30);
		Charlie.printStatus();
		Charlie.attack("Erwan");
		Erwan.takeDamage(30);
		Charlie.attack("Erwan");
		Erwan.takeDamage(30);
		Charlie.attack("Erwan");
		Erwan.takeDamage(30);
		Charlie.attack("Erwan");
		Erwan.takeDamage(30);
		Erwan.printStatus();
		Charlie.printStatus();

		std::cout << std::endl << "---------- BE REPAIRED ----------" << std::endl << std::endl;
		Charlie.beRepaired(5);
		Charlie.printStatus();
		Erwan.beRepaired(90);
		Erwan.printStatus();

		std::cout << std::endl << "---------- ATTACK UNTIL NOR MORE ENERGY ----------" << std::endl << std::endl;
		for (int i = 0; i < 43; i++)
			Charlie.attack("Erwan");
		Charlie.beRepaired(5);
		Charlie.printStatus();
		std::cout << std::endl << "---------- IS DEAD ----------" << std::endl << std::endl;
		Erwan.attack("Charlie");
		Erwan.printStatus();
		Erwan.takeDamage(10);
		Erwan.highFivesGuys();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	ClapTrap* ptr = new DiamondTrap("D2");
	ptr->attack("Target");
	delete ptr;
	return 0;
}
