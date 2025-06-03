#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
	// {
	// 	std::cout << "------  BRAIN ONLY  ------" << std::endl;

	// 	std::cout << "------  CONSTRUCTORS  ------" << std::endl;
	// 	Brain a;
	// 	Brain c;

	// 	std::cout << std::endl << "------  COPY  ------" << std::endl;
	// 	Brain b(a);

	// 	std::cout << std::endl << "------  OPERATOR  ------" << std::endl;
	// 	c = b;
	// 	c.setIdea(2, "this is a new idea");
	// 	std::cout << std::endl << "------  b IDEAS  ------" << std::endl;
	// 	for (int i = 0; i < 100; i++)
	// 		std::cout << b.getIdea(i) << ", ";
	// 	std::cout << std::endl;
	// 	std::cout << std::endl << "------  c IDEAS  ------" << std::endl;
	// 	for (int i = 0; i < 100; i++)
	// 		std::cout << c.getIdea(i) << ", ";
	// 	std::cout << std::endl;
	// 	std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
	// }
	// std::cout << std::endl;
	// {
	// 	const Animal* j = new Dog();
	// 	delete j;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << "------  CONSTRUCTORS  ------" << std::endl;
	// 	Dog* j = new Dog();

	// 	std::cout << std::endl << "------  COPY  ------" << std::endl;
	// 	Dog copy = *j;
	// 	std::cout << "My dog type is : " << copy.getType() << " " << std::endl;
	// 	std::cout << "My dog sound is : ";
	// 	copy.makeSound();
	// 	copy.getBrain()->setIdea(2, "idea 2 was changed");
	// 	for (int i = 0; i < 100; i++)
	// 		std::cout << j->getBrain()->getIdea(i) << ", ";
	// 	std::cout << std::endl << std::endl;
	// 	for (int i = 0; i < 100; i++)
	// 		std::cout << copy.getBrain()->getIdea(i) << ", ";
	// 	std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
	// 	delete j;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << "------  CONSTRUCTORS  ------" << std::endl;
	// 	Dog test;
	// 	Dog test2;

	// 	std::cout << std::endl << "------  OPERATOR =  ------" << std::endl;
	// 	test2 = test; // operator = only called when both classes are constructed while copy constructor is called when directly = when building
	// 	test2.getBrain()->setIdea(2, "idea 2 was changed");
	// 	for (int i = 0; i < 100; i++)
	// 		std::cout << test.getBrain()->getIdea(i) << ", ";
	// 	std::cout << std::endl << std::endl;
	// 	for (int i = 0; i < 100; i++)
	// 		std::cout << test2.getBrain()->getIdea(i) << ", ";
	// 	std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
	// }
	// std::cout << std::endl;
	{
		std::cout << "------  CONSTRUCTORS  ------" << std::endl;
		Animal* meta[4];
		for (int i = 0; i < 2; i++)
			meta[i] = new Dog();
		for (int i = 2; i < 4; i++)
			meta[i] = new Cat();
		std::cout << std::endl << "------  DETRUCTORS  ------" << std::endl;
		for (int i = 0; i < 4; i++)
			delete meta[i];
	}
	return 0;
}
