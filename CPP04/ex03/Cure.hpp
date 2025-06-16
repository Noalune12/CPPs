/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:12 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:13 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"

class Cure: public AMateria {

	public:
		Cure();
		Cure(Cure const& src);
		~Cure();

		Cure& operator=(Cure const& name);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
