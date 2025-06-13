/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuisson <lbuisson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:32:36 by lbuisson          #+#    #+#             */
/*   Updated: 2025/06/13 10:32:37 by lbuisson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

// #define TRY_CREATE_ANIMAL

int main()
{
	{
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		#ifdef TRY_CREATE_ANIMAL
			Animal animal;
		#endif
		Animal* dog = new Dog;
		Animal* cat = new Cat;

		std::cout << std::endl << "------  GET TYPE  ------" << std::endl;
		std::cout << "My dog type is : " << dog->getType() << " " << std::endl;
		std::cout << "My cat type is : " << cat->getType() << " " << std::endl;

		std::cout << std::endl << "------  MAKE SOUND  ------" << std::endl;
		std::cout << "My cat sound is : ";
		cat->makeSound();
		std::cout << "My dog sound is : ";
		dog->makeSound();

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
		delete dog;
		delete cat;
	}
	return 0;
}
