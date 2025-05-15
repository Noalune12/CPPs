#include "Harl.hpp"

#include <iostream>

Harl::Harl() {
	return ;
}

Harl::~Harl() {
	return ;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl << "🍦 🛠️" << std::endl << "I think I just saw the ‘vanilla and chocolate’ ice cream flavor on the menu." << std::endl << "I really love it, especially with a ton of whipped cream and chocolate sprinkles on top!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl << "🍦 ℹ️" << std::endl << "I’ve got my ice cream cone in hand." << std::endl << "It’s a good mix of vanilla and chocolate swirls." << std::endl << "However, the whipped cream is a bit tasteless, I was hoping for a better taste." << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl << "🍦 ⚠️" << std::endl << "My ice cream is melting faster than I can eat it." << std::endl << "I might need to pick up the pace... or switch to a cup!" << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl << "🍦 ❌" << std::endl << "My ice cream is falling off my cone, and my hands are too sticky to fix this. " << std::endl << "Immediate intervention required—time to find napkins or risk a full meltdown." << std::endl;
}

void	Harl::complain( std::string level) {
	std::string levelName[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*levelFunction[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++) {
		if (level == levelName[i]) {
			(this->*levelFunction[i])();
			return ;
		}
	}
	std::cout << "Invalid entry : " << level << std::endl;
}
