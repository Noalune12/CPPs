#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const& src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& src);

    	void executeForm(Bureaucrat const & executor) const;

    private:
        std::string _target;    
};

#endif