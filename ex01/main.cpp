#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"
# define AMOUNT 10

int main()
{
	{
		std::cout << YELLOW << "------  BRAIN ONLY  ------" << RESET << std::endl;

		std::cout << BLUE << "------  CONSTRUCTORS  ------" << RESET << std::endl;
		Brain a;
		Brain c;

		std::cout << BLUE << "\n------  COPY  ------" << RESET << std::endl;
		Brain b(a);

		std::cout << std::endl << BLUE << "------  OPERATOR  ------" << RESET << std::endl;
		c = b;
		c.setIdea(2, "this is a new idea");

		std::cout << BLUE << "\n------  b IDEAS  ------" << RESET << std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << b.getIdea(i) << ", ";

		std::cout << BLUE << "\n\n------  c IDEAS  ------" << RESET << std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << c.getIdea(i) << ", ";
		std::cout << std::endl;
		std::cout << BLUE << std::endl << "------  DETRUCTORS  ------" << RESET << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "------  TEST WITH ARRAY  ------" << RESET << std::endl;
		std::cout << BLUE << "------  CONSTRUCTORS  ------" << RESET << std::endl;
		Animal* meta[AMOUNT];
		for (int i = 0; i < AMOUNT / 2; i++)
			meta[i] = new Dog();
		for (int i = AMOUNT / 2; i < AMOUNT; i++)
			meta[i] = new Cat();
		std::cout << BLUE << std::endl << "------  MAKE SOUND  ------" << RESET << std::endl;
		for (int i = 0; i < AMOUNT; i++)
			meta[i]->makeSound();
		std::cout << BLUE << std::endl << "------  DETRUCTORS  ------" << RESET << std::endl;
		for (int i = 0; i < AMOUNT; i++)
			delete meta[i];
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW << "------  COPY TEST  ------" << RESET << std::endl;
		std::cout << BLUE << "------  CONSTRUCTORS  ------" << RESET << std::endl;
		Dog* j = new Dog();

		std::cout << BLUE << std::endl << "------  COPY  ------" << RESET << std::endl;
		Dog *copy = new Dog(*j);
		Dog *copy2 = NULL;
		std::cout << "\n" << std::endl;
		std::cout << "My dog type is : " << copy->getType() << " " << RESET << std::endl;
		std::cout << "My dog sound is : ";
		copy->makeSound();

		std::cout << std::endl << BLUE << "------  BRAIN  ------" << RESET << std::endl;
		std::cout << BLUE << "\n------  copy IDEAS  ------" << RESET << std::endl;
		copy->setIdea(0, "I replace idea at index 0 only for the copy");
		for (int i = 0; i < 100; i++)
			std::cout << copy->getIdea(i) << ", ";
		std::cout << BLUE << "\n\n------  copy2 copied ------" << RESET << std::endl;
		copy2 = new Dog(*j);
		copy2->setIdea(99, "be careful");
		std::cout << BLUE << "\n\n------  src IDEAS  ------" << RESET << std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << j->getIdea(i) << ", ";
		std::cout << BLUE << "\n\n------  copy2 IDEAS (after copy) ------" << RESET << std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << copy2->getIdea(i) << ", ";
		std::cout << BLUE << "\n\n------  DETRUCTORS  ------" << RESET << std::endl;
		delete j;
		delete copy;
		delete copy2;
	}
	return 0;
}
