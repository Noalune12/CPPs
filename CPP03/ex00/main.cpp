/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:58:59 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:00 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int	main( void ) {
	{
		ClapTrap	Charlie("Charlie");
		ClapTrap	Erwan("Erwan");

		std::cout << std::endl << "---------- ATTACK AND TAKE DAMAGES ----------" << std::endl << std::endl;
		Charlie.attack("Erwan");
		Erwan.attack("Charlie");
		Erwan.takeDamage(10);
		Erwan.printStatus();
		Charlie.takeDamage(5);
		Charlie.printStatus();

		std::cout << std::endl << "---------- BE REPAIRED ----------" << std::endl << std::endl;
		Charlie.beRepaired(5);
		Charlie.printStatus();
		Erwan.beRepaired(90);
		Erwan.printStatus();

		std::cout << std::endl << "---------- ATTACK UNTIL NOR MORE ENERGY ----------" << std::endl << std::endl;
		for (int i = 0; i < 10; i++)
			Charlie.attack("Erwan");
		Charlie.beRepaired(5);
		Charlie.printStatus();
		std::cout << std::endl << "---------- IS DEAD ----------" << std::endl << std::endl;
		Erwan.attack("Charlie");
		Erwan.printStatus();
		Erwan.takeDamage(10);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		ClapTrap	Zeus("Zeus");
		ClapTrap	ZeusCopy(Zeus);

		std::cout << std::endl << "---------- ZEUS MAX REPAIR ----------" << std::endl << std::endl;
		ZeusCopy.beRepaired(4294967295);
		ZeusCopy.printStatus();
		ZeusCopy.beRepaired(4294967285);
		ZeusCopy.printStatus();
		std::cout << std::endl;
	}
	return 0;
}
