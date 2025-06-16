/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:32:14 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:32:15 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {

	public:
		Cat();
		Cat(Cat const& src);
		~Cat();

		Cat& operator=(Cat const& name);

		void makeSound() const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;

	private:
		Brain* brain;
};

#endif
