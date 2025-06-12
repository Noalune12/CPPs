#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {

	public:
		Cat();
		Cat(Cat const& src);
		~Cat();

		Cat& operator=(Cat const& name);

		void makeSound() const;
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;

	private:
		Brain* brain;
};

#endif
