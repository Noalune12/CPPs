#ifndef FORM_H
#define FORM_H

#include <string>
#include <exception>

class Bureaucrat;

class AForm {

	public:
		AForm();
		AForm(const std::string name, const int sign, const int exec);
		AForm(AForm const& src);
		virtual ~AForm() = 0;

		AForm& operator=(AForm const& src);

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat const& name);
		void execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormIsNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
		virtual void executeForm() const = 0;
};

std::ostream& operator<<(std::ostream& o, AForm const& name);

#endif
