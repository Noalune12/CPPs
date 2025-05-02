#include "Harl.hpp"

#include <iostream>

Harl::Harl() {
	return ;
}

Harl::~Harl() {
	return ;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl << "🍦 🛠️" << std::endl << "I think I just saw the ‘vanilla and chocolate’ ice cream flavor on the menu." << std::endl << "I really love it, especially with a ton of whipped cream and chocolate sprinkles on top!" << std::endl << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl << "🍦 ℹ️" << std::endl << "I’ve got my ice cream cone in hand." << std::endl << "It’s a good mix of vanilla and chocolate swirls." << std::endl << "However, the whipped cream is a bit tasteless, I was hoping for a better taste." << std::endl << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl << "🍦 ⚠️" << std::endl << "My ice cream is melting faster than I can eat it." << std::endl << "I might need to pick up the pace... or switch to a cup!" << std::endl << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl << "🍦 ❌" << std::endl << "My ice cream is falling off my cone, and my hands are too sticky to fix this. " << std::endl << "Immediate intervention required—time to find napkins or risk a full meltdown." << std::endl << std::endl;
}

void	Harl::complain( std::string level) {
	std::string levelName[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int	index = 0;
	while (index < 4) {
		if (level.compare(levelName[index]) == 0)
			break ;
		index++;
	}
	switch (index) {
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
