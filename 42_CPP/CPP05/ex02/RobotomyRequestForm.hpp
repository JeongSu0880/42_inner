#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private :
        std::string mTarget;
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &original);
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &original);

        void execute(const Bureaucrat &b) const;
};
