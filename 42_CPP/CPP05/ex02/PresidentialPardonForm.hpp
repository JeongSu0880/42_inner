#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private :
        std::string mTarget;
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &original);
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &original);

        void execute(const Bureaucrat &b) const;
};
