#pragma once

#include <fstream>
#include <iostream>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
	private: 
		std::string mTarget;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);

		class FileNotOpenException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void execute(const Bureaucrat &b) const;
};