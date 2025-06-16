/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:30:57 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:30:59 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat: public Animal {

	public:
		Cat();
		Cat(Cat const& src);
		~Cat();

		Cat& operator=(Cat const& name);

		void makeSound() const;
};

#endif
