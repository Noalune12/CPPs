/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:30:52 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:30:54 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal {

	public:
		Animal(void);
		Animal(Animal const& src);
		virtual ~Animal(void);

		Animal& operator=(Animal const& name);

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
