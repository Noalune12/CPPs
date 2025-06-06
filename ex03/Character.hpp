#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

# define GREEN "\033[32m"
# define RED "\033[31m"
// # define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
// # define PURPLE "\033[0;35m"
// # define CYAN "\033[36m"
# define RESET "\033[0m"

class Character: public ICharacter {

	public:
		Character();
		Character(std::string name);
		Character(Character const& src);
		~Character();

		Character& operator=(Character const& src);

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria* inventory[4];
		AMateria** ground;
		int groundCapacity;
		int groundSize;
};

#endif
