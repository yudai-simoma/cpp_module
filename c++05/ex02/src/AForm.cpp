/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:28 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 15:44:10 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
    : _name(""),
      _isSigned(false),
      _gradeRequiredToSign(150),
      _gradeRequiredToExecute(150) {
    std::cout << RED_START << "AForm: Default constructor" << COLOR_END
              << std::endl;
}

AForm::AForm(std::string const& name, int gradeRequiredToSign,
             int gradeRequiredToExecute)
    : _name(name),
      _isSigned(false),
      _gradeRequiredToSign(gradeRequiredToSign),
      _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign <= 0 || gradeRequiredToExecute <= 0) {
        throw AForm::GradeTooHighException();
    }
    if (gradeRequiredToSign >= 151 || gradeRequiredToExecute >= 151) {
        throw AForm::GradeTooLowException();
    }
    std::cout << RED_START << "AForm: constructor called with " << *this
              << COLOR_END << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(false),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute) {
    std::cout << RED_START << "AForm: Copy constructor" << COLOR_END
              << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_isSigned = other._isSigned;
        this->_gradeRequiredToSign = other._gradeRequiredToSign;
        this->_gradeRequiredToExecute = other._gradeRequiredToExecute;
    }
    std::cout << RED_START << "AForm: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << RED_START << "AForm: Destructor called for " << this->_name
              << " (signed: " << (this->_isSigned ? "true" : "false")
              << ", sign grade: " << this->_gradeRequiredToSign
              << ", execute grade: " << this->_gradeRequiredToExecute << ")"
              << COLOR_END << std::endl;
}

std::string const& AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return this->_gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return this->_gradeRequiredToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (this->_isSigned == true) {
        throw AForm::AlreadySignedException();
    } else if (this->_gradeRequiredToSign >= bureaucrat.getGrade()) {
        this->_isSigned = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

void AForm::isExecutable(Bureaucrat const& bureaucrat) const {
    if (!this->_isSigned) {
        throw AForm::NotSignedException();
    }
    if (this->_gradeRequiredToExecute < bureaucrat.getGrade()) {
        throw AForm::GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::AlreadySignedException::what() const throw() {
    return "AForm is already signed.";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm is not signed.";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "name: " << form.getName() << ", isSigned: " << form.getIsSigned()
       << ", gradeRequiredToSign: " << form.getGradeRequiredToSign()
       << ", gradeRequiredToExecute: " << form.getGradeRequiredToExecute();
    return os;
}
