#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat: public Animal {

	public:
		Cat();
		Cat(Cat const& src);
		~Cat();

		Cat& operator=(Cat const& name);

		void makeSound() const;
		std::string getType() const;
};

#endif
