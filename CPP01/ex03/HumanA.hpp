#ifndef HUMANA_H
# define HUMANA_H

#include <string>
#include "Weapon.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class HumanA {

	public :

		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack() const;

	private :

		std::string	_name;
		Weapon		&_weapon;
};

#endif
