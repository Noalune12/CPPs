#ifndef AMATERIA_H
# define AMATERIA_H

#include <string>

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(std::string const& type);
		AMateria();
		AMateria(AMateria const& src);
		virtual ~AMateria();

		AMateria& operator=(AMateria const& name);

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target);
};

#endif
