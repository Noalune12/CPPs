#ifndef FORM_H
#define FORM_H

#include <string>
#include <exception>

class Bureaucrat;

class Form {

	public:
		Form();
		Form(const std::string name, const int sign, const int exec);
		Form(Form const& src);
		~Form();

		Form& operator=(Form const& src);

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat const& name);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
};

std::ostream& operator<<(std::ostream& o, Form const& name);

#endif
