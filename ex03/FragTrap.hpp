#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap(FragTrap const& src);
		FragTrap& operator=(FragTrap const& name);
		~FragTrap( void );

		void highFivesGuys(void);
		void	attack( const std::string& target );
};

#endif
