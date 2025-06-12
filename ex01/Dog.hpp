#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {

	public:
		Dog();
		Dog(Dog const& src);
		~Dog();

		Dog& operator=(Dog const& name);

		void makeSound() const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;

	private:
		Brain* brain;
};

#endif
