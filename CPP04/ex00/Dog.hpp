/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:03 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:05 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog: public Animal {

	public:
		Dog();
		Dog(Dog const& src);
		~Dog();

		Dog& operator=(Dog const& name);

		void makeSound() const;
};

#endif
