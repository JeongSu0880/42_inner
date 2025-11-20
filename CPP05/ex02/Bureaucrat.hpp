#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string mName;
		int	mGrade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &original);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &original);

		const std::string &getName() const;
		const int &getGrade() const;
		
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &f) const;
		void executeForm(const AForm &f) const;
	
		class GradeTooHighException : public std::exception {
			public:
				char const *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				char const *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
