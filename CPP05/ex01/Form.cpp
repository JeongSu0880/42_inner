#include "Form.hpp"

Form::Form() : mName("defaultForm"), mSignedStatus(false), mSignedGrade(150), mExecutedGrade(150) {
}

Form::Form(const std::string &name, const int &signedGrade, const int &executedGrade) : mName(name), mSignedStatus(false), mSignedGrade(signedGrade), mExecutedGrade(executedGrade) {
	if (signedGrade < 1 || executedGrade < 1) {
		throw Form::GradeTooHighException();
	}
	if (signedGrade > 150 || executedGrade > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &original) : mName(original.mName), mSignedGrade(original.mSignedGrade), mExecutedGrade(original.mExecutedGrade) {
	*this = original;
}

Form::~Form() {
}

Form &Form::operator=(const Form &original) {
	mSignedStatus = original.mSignedStatus;
	return (*this);
}

const std::string &Form::getName() const {
	return mName;
}

const bool &Form::getSignedStatus() const {
	return mSignedStatus;
}

const int &Form::getSignedGrade() const {
	return mSignedGrade;
}

const int &Form::getExecutedGrade() const {
	return mExecutedGrade;
}

void Form::beSigned(const Bureaucrat &b) {

	if (b.getGrade() <= mSignedGrade) {
		mSignedStatus = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << f.getName() << std::endl;
	out << "Signed Status : " << f.getSignedStatus() << std::endl;
	out << "Signed Grade : " << f.getSignedGrade() << std::endl;
	out << "Executed Grade : " << f.getExecutedGrade() << std::endl;
	return out;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}