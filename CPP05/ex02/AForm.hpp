#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string mName;
		bool mSignedStatus;
		const int mSignedGrade;
		const int mExecutedGrade;

	public:
		AForm();
		AForm(const std::string &name, const int &signedGrade, const int &executedGrade);
		AForm(const AForm &original);
		~AForm();

		AForm &operator=(const AForm &original);

		const std::string &getName() const;
		const bool &getSignedStatus() const;
		const int &getSignedGrade() const;
		const int &getExecutedGrade() const;

		void beSigned(const Bureaucrat &b);
		virtual void execute(const Bureaucrat &b) const;
		
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);