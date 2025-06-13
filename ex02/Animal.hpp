/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:57 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:58 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include "Brain.hpp"

#include <string>

class Animal {

	public:
		Animal(void);
		Animal(Animal const& src);
		virtual ~Animal(void);

		Animal& operator=(Animal const& name);

		virtual void makeSound() const = 0;
		std::string getType() const;
		virtual void setIdea(int index, std::string idea) = 0;
		virtual std::string getIdea(int index) const = 0;

	protected:
		std::string type;
};

#endif
