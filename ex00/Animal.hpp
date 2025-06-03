#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal {

	public:
		Animal(void);
		Animal(Animal const& src);
		virtual ~Animal(void);

		Animal& operator=(Animal const& name);

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
