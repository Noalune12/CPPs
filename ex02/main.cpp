#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
	{
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		// Animal animal;
		Dog dog;
		Cat cat;

		std::cout << std::endl << "------  GET TYPE  ------" << std::endl;
		std::cout << "My dog type is : " << dog.getType() << " " << std::endl;
		std::cout << "My cat type is : " << cat.getType() << " " << std::endl;

		std::cout << std::endl << "------  MAKE SOUND  ------" << std::endl;
		std::cout << "My cat sound is : ";
		cat.makeSound();
		std::cout << "My dog sound is : ";
		dog.makeSound();
		std::cout << "My animal sound is : ";
		// animal.makeSound();

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		// const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl << "------  GET TYPE  ------" << std::endl;
		std::cout << "My dog type is : " << j->getType() << " " << std::endl;
		std::cout << "My cat type is : " << i->getType() << " " << std::endl;

		std::cout << std::endl << "------  MAKE SOUND  ------" << std::endl;
		std::cout << "My cat sound is : ";
		i->makeSound();
		std::cout << "My dog sound is : ";
		j->makeSound();
		std::cout << "My animal sound is : ";
		// meta->makeSound();

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
		// delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		Dog* j = new Dog();

		std::cout << std::endl << "------  COPY  ------" << std::endl;
		Dog copy = *j;
		std::cout << "My dog type is : " << copy.getType() << " " << std::endl;
		std::cout << "My dog sound is : ";
		copy.makeSound();

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
		delete j;
	}
	std::cout << std::endl;
	{
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		Dog test;
		Dog test2;

		std::cout << std::endl << "------  OPERATOR =  ------" << std::endl;
		test2 = test; // operator = only called when both classes are constructed while copy constructor is called when directly = when building

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
	}
	return 0;
}
