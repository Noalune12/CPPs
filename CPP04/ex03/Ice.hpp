/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:19 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:21 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"

class Ice: public AMateria {

	public:
		Ice();
		Ice(Ice const& src);
		~Ice();

		Ice& operator=(Ice const& name);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
