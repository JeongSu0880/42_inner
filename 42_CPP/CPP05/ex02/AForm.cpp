#include "AForm.hpp"

AForm::AForm() : mName("defaultForm"), mSignedStatus(false), mSignedGrade(150), mExecutedGrade(150) {
}

AForm::AForm(const std::string &name, const int &signedGrade, const int &executedGrade) : mName(name), mSignedStatus(false), mSignedGrade(signedGrade), mExecutedGrade(executedGrade) {
	if (signedGrade < 1 || executedGrade < 1) {
		throw AForm::GradeTooHighException();
	}
	if (signedGrade > 150 || executedGrade > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm &original) : mName(original.mName), mSignedGrade(original.mSignedGrade), mExecutedGrade(original.mExecutedGrade) {
	*this = original;
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &original) {
	if (this != &original) {
		mSignedStatus = original.mSignedStatus;
	}
	return (*this);
}

const std::string &AForm::getName() const {
	return mName;
}

const bool &AForm::getSignedStatus() const {
	return mSignedStatus;
}

const int &AForm::getSignedGrade() const {
	return mSignedGrade;
}

const int &AForm::getExecutedGrade() const {
	return mExecutedGrade;
}

void AForm::beSigned(const Bureaucrat &b) {

	if (b.getGrade() <= mSignedGrade) {
		mSignedStatus = true;
		std::cout << "Form is signed by " << b.getName() << std::endl;
	} else {
		throw AForm::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << f.getName() << std::endl;
	out << "Signed Status : " << f.getSignedStatus() << std::endl;
	out << "Signed Grade : " << f.getSignedGrade() << std::endl;
	out << "Executed Grade : " << f.getExecutedGrade() << std::endl;
	return out;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed.";
}

void AForm::execute(const Bureaucrat &b) const {
	if (!mSignedStatus) {
		throw AForm::FormNotSignedException();
	}

	if (b.getGrade() > mExecutedGrade) {
		throw AForm::GradeTooLowException();
	}

	std::cout << "Form is executed by " << b.getName() << std::endl;
}