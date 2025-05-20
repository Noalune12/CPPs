#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int	main( void ) {
	{
		ScavTrap	Charlie("Charlie");
		ScavTrap	Erwan("Erwan");


		std::cout << std::endl << "---------- GUARD GATE ----------" << std::endl << std::endl;
		Charlie.guardGate();
		Erwan.guardGate();

		std::cout << std::endl << "---------- ATTACK AND TAKE DAMAGES ----------" << std::endl << std::endl;
		Charlie.attack("Erwan");
		Erwan.attack("Charlie");
		Erwan.takeDamage(20);
		Erwan.printStatus();
		Charlie.takeDamage(20);
		Charlie.printStatus();
		Charlie.attack("Erwan");
		Erwan.takeDamage(20);
		Charlie.attack("Erwan");
		Erwan.takeDamage(20);
		Charlie.attack("Erwan");
		Erwan.takeDamage(20);
		Charlie.attack("Erwan");
		Erwan.takeDamage(20);
		Erwan.printStatus();
		Charlie.printStatus();

		std::cout << std::endl << "---------- BE REPAIRED ----------" << std::endl << std::endl;
		Charlie.beRepaired(5);
		Charlie.printStatus();
		Erwan.beRepaired(90);
		Erwan.printStatus();

		std::cout << std::endl << "---------- ATTACK UNTIL NOR MORE ENERGY ----------" << std::endl << std::endl;
		for (int i = 0; i < 45; i++)
			Charlie.attack("Erwan");
		Charlie.beRepaired(5);
		Charlie.printStatus();
		std::cout << std::endl << "---------- IS DEAD ----------" << std::endl << std::endl;
		Erwan.attack("Charlie");
		Erwan.printStatus();
		Erwan.takeDamage(10);
		Erwan.guardGate();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		ScavTrap	Zeus("Zeus");

		std::cout << std::endl << "---------- ZEUS MAX REPAIR ----------" << std::endl << std::endl;
		Zeus.beRepaired(4294967295);
		Zeus.printStatus();
		for (int i = 0; i < 49; i++)
			Zeus.beRepaired(1);
		Zeus.beRepaired(4294967146);
		Zeus.printStatus();
		Zeus.attack("Hades");
		Zeus.guardGate();
		std::cout << std::endl;
	}

	// ClapTrap* tmp = new ScavTrap(); // virtual added to take dynamically the attack and destructor of fragtrap -> do not take the instance (claptrap)  of class but the object real of the thing (scavtrap) at compilation
	// tmp->attack("THOMAS");
	// delete tmp;
	return 0;
}
