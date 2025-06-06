/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:26 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:27 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int	main( void ) {
	{
		FragTrap	Charlie("Charlie");
		FragTrap	Erwan("Erwan");


		std::cout << std::endl << "---------- High Fives ----------" << std::endl << std::endl;
		Charlie.highFivesGuys();
		Erwan.highFivesGuys();

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
		for (int i = 0; i < 94; i++)
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
	{
		FragTrap	Zeus("Zeus");
		FragTrap	ZeusCopy(Zeus);

		std::cout << std::endl << "---------- ZEUS MAX REPAIR ----------" << std::endl << std::endl;
		ZeusCopy.beRepaired(4294967295);
		ZeusCopy.printStatus();
		for (int i = 0; i < 99; i++)
			ZeusCopy.beRepaired(1);
		ZeusCopy.beRepaired(4294967096);
		ZeusCopy.printStatus();
		ZeusCopy.attack("Hades");
		ZeusCopy.highFivesGuys();
		std::cout << std::endl;
	}
	return 0;
}
