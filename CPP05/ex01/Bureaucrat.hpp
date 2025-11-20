#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

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

		void signForm(Form &f) const;

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
