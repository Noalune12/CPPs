/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:33:01 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:33:03 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "Storage.hpp"

class Character: public ICharacter {

	public:
		Character();
		Character(std::string name);
		Character(Character const& src);
		~Character();

		Character& operator=(Character const& src);

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria* _inventory[4];
		Storage _ground;
};

#endif
