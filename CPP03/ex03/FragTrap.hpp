/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:59:47 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/06 11:59:48 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
