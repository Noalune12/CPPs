/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:56 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:57 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap(ScavTrap const& src);
		ScavTrap& operator=(ScavTrap const& name);
		~ScavTrap( void );

		void	guardGate( void );
		void	attack( const std::string& target );
};

#endif
