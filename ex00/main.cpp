#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

int main()
{
	{
		std::cout << YELLOW << "------  TEST WITH SIMPLE DECLARATION  ------" << RESET << std::endl;
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		Animal animal;
		Dog dog;
		Cat cat;

		std::cout << std::endl << "------  GET TYPE  ------" << std::endl;
		std::cout << "My dog type is : " << dog.getType() << " " << std::endl;
		std::cout << "My cat type is : " << cat.getType() << " " << std::endl;
		std::cout << "My Animal type is : " << animal.getType() << " " << std::endl;

		std::cout << std::endl << "------  MAKE SOUND  ------" << std::endl;
		std::cout << "My cat sound is : ";
		cat.makeSound();
		std::cout << "My dog sound is : ";
		dog.makeSound();
		std::cout << "My animal sound is : ";
		animal.makeSound();

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "------  TEST WITH POINTER DECLARATION  ------" << RESET << std::endl;
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		const Animal* meta = new Animal();
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
		meta->makeSound();

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "------  COPY TEST  ------" << RESET << std::endl;
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
		std::cout << YELLOW << "------  WRONG ANIMAL  ------" << RESET << std::endl;
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << std::endl << "------  GET TYPE  ------" << std::endl;
		std::cout << "My cat type is : " << i->getType() << " " << std::endl;

		std::cout << std::endl << "------  MAKE SOUND  ------" << std::endl;
		std::cout << "My cat sound is : ";
		i->makeSound();
		std::cout << "My animal sound is : ";
		meta->makeSound();

		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
		delete meta;
		delete i;
	}
	return 0;
}
