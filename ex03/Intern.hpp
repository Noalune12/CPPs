#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class Intern {

	public:
		Intern();
		Intern(Intern const& src);
		~Intern();

		Intern& operator=(Intern const& src);

		AForm* makeForm(std::string name, std::string target) const;

	private:
		AForm* createShrubberyForm(std::string target) const;
		AForm* createRobotomyForm(std::string target) const;
		AForm* createPresidentialForm(std::string target) const;
};

#endif
