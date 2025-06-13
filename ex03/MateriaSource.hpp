/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:38 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:39 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "Storage.hpp"

class MateriaSource: public IMateriaSource {

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& src);
		~MateriaSource();

		MateriaSource& operator=(MateriaSource const& src);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const& type);

	private:
		AMateria* _inventory[4];
		Storage _storage;
};

#endif
