/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:28 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 15:44:19 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
    : _name(""),
      _isSigned(false),
      _gradeRequiredToSign(150),
      _gradeRequiredToExecute(150) {
    std::cout << RED_START << "Form: Default constructor" << COLOR_END
              << std::endl;
}

Form::Form(std::string const& name, int gradeRequiredToSign,
           int gradeRequiredToExecute)
    : _name(name),
      _isSigned(false),
      _gradeRequiredToSign(gradeRequiredToSign),
      _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign <= 0 || gradeRequiredToExecute <= 0) {
        throw Form::GradeTooHighException();
    }
    if (gradeRequiredToSign >= 151 || gradeRequiredToExecute >= 151) {
        throw Form::GradeTooLowException();
    }
    std::cout << RED_START << "Form: constructor called with " << *this
              << COLOR_END << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name),
      _isSigned(false),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute) {
    std::cout << RED_START << "Form: Copy constructor" << COLOR_END
              << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_isSigned = other._isSigned;
        this->_gradeRequiredToSign = other._gradeRequiredToSign;
        this->_gradeRequiredToExecute = other._gradeRequiredToExecute;
    }
    std::cout << RED_START << "Form: Copy assignment" << COLOR_END << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << RED_START << "AForm: Destructor called for " << this->_name
              << " (signed: " << (this->_isSigned ? "true" : "false")
              << ", sign grade: " << this->_gradeRequiredToSign
              << ", execute grade: " << this->_gradeRequiredToExecute << ")"
              << COLOR_END << std::endl;
}

std::string const& Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getGradeRequiredToSign() const {
    return this->_gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return this->_gradeRequiredToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (this->_isSigned == true) {
        throw Form::AlreadySignedException();
    } else if (this->_gradeRequiredToSign >= bureaucrat.getGrade()) {
        this->_isSigned = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* Form::AlreadySignedException::what() const throw() {
    return "Form is already signed.";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "name: " << form.getName() << ", isSigned: " << form.getIsSigned()
       << ", gradeRequiredToSign: " << form.getGradeRequiredToSign()
       << ", gradeRequiredToExecute: " << form.getGradeRequiredToExecute();
    return os;
}
