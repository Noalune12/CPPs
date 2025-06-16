/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:32:55 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:32:57 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>

class ICharacter;

class AMateria {

	protected:
		std::string	_type;

	public:
		AMateria(std::string const& type);
		AMateria();
		AMateria(AMateria const& src);
		virtual ~AMateria();

		AMateria& operator=(AMateria const& name);

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
