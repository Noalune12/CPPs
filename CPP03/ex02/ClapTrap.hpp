/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:19 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:20 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
