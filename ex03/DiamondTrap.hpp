#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap(DiamondTrap const& src);
		DiamondTrap& operator=(DiamondTrap const& name);
		~DiamondTrap( void );

		void	whoAmI();
		void	attack(const std::string& target);

	private:
		std::string	_name;
};

#endif
