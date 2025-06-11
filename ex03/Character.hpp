#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "Storage.hpp"

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
		void printGround() const;

	private:
		std::string _name;
		AMateria* _inventory[4];
		Storage _ground;
};

#endif
