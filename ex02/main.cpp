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
