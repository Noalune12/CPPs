/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:42 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:43 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
