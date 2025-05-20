#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define RESET "\033[0m"

class ClapTrap {

	public:

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const& src );
		virtual ~ClapTrap( void );

		ClapTrap& operator=( ClapTrap const& name );

		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;
		std::string		getName( void ) const;

		void			virtual attack( const std::string& target );
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			printStatus( void ) const;

	protected:

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
