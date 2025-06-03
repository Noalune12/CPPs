#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>

class WrongAnimal {

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const& src);
		~WrongAnimal(void);

		WrongAnimal& operator=(WrongAnimal const& name);

		void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
