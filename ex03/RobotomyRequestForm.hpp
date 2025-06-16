#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(RobotomyRequestForm const& src);

		void executeForm() const;

	private:
		std::string _target;
};

#endif
