#ifndef ANIMAL_H
# define ANIMAL_H

#include "Brain.hpp"

#include <string>

class Animal {

	public:
		Animal(void);
		Animal(Animal const& src);
		virtual ~Animal(void);

		Animal& operator=(Animal const& name);

		virtual void makeSound() const;
		std::string getType() const;
		virtual void setIdea(int index, std::string idea);
		virtual std::string getIdea(int index) const;

	protected:
		std::string type;
};

#endif
