#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), _target("Unknown") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src): AForm(src), _target(src._target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src) {
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeForm() const {
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
		throw std::ios_base::failure("Fail to open the file");
	outfile << "           &&& &&  & &&                 \n";
	outfile << "       && &\\/&\\|& ()|/ @, &&            \n";
	outfile << "       &\\/(/&/&||/& /_/)_&/_&           \n";
	outfile << "    &() &\\/&|()|/&\\/ '%\" & ()           \n";
	outfile << "   &_\\_&&_\\ |& |&&/&__%_/_& &&          \n";
	outfile << " &&   && & &| &| /& & % ()& /&&         \n";
	outfile << "  ()&_---()&\\&\\|&&-&&--%---()~          \n";
	outfile << "     &&     \\||         &&             \n";
	outfile << "             |||                        \n";
	outfile << "             |||                        \n";
	outfile << "             |||                        \n";
	outfile << "      ______/|||\\_______                \n";
	outfile << "     |                   |              \n";
	outfile << "     |___________________|              \n";
	outfile << "     (_)               (_)              \n";
	outfile.close();
}
