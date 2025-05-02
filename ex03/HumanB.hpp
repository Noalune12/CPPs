#ifndef HUMAN_B
# define HUMAN_B

#include "Weapon.hpp"

#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class	HumanB {

	public :

		HumanB(std::string name);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon &weapon);

	private :

		std::string	_name;
		Weapon		*_weapon;
};

#endif
