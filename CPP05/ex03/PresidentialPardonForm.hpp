#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(PresidentialPardonForm const& src);

		void executeForm() const;

	private:
		std::string _target;
};

#endif
