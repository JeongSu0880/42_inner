#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string mName;
		bool mSignedStatus;
		const int mSignedGrade;
		const int mExecutedGrade;

	public:
		Form();
		Form(const std::string &name, const int &signedGrade, const int &executedGrade);
		Form(const Form &original);
		~Form();

		Form &operator=(const Form &original);

		const std::string &getName() const;
		const bool &getSignedStatus() const;
		const int &getSignedGrade() const;
		const int &getExecutedGrade() const;

		void beSigned(const Bureaucrat &b);
		
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &f);