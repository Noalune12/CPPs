/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:16 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:17 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

	public:
		WrongCat();
		WrongCat(WrongCat const& src);
		~WrongCat();

		WrongCat& operator=(WrongCat const& name);

		void makeSound() const;
};

#endif
