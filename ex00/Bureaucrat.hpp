#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const& src);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade(int score);
		void decrementGrade(int score);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& name);

#endif
