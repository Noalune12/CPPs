/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:31:47 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:31:48 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>

class WrongAnimal {

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const& src);
		~WrongAnimal(void);

		WrongAnimal& operator=(WrongAnimal const& name);

		void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
