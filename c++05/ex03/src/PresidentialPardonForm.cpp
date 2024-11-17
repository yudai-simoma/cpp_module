/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:20:04 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 16:57:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("", this->GRADE_REQUIRED_TO_SIGN, this->GRADE_REQUIRED_TO_EXECUTE),
      _target("") {
    std::cout << RED_START << "PresidentialPardonForm: Default constructor"
              << COLOR_END << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target,
                                               std::string const& name,
                                               int gradeRequiredToSign,
                                               int gradeRequiredToExecute)
    : AForm(name, gradeRequiredToSign, gradeRequiredToExecute),
      _target(target) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeRequiredToSign > this->GRADE_REQUIRED_TO_SIGN ||
        gradeRequiredToExecute > this->GRADE_REQUIRED_TO_EXECUTE) {
        throw AForm::GradeTooLowException();
    }
    std::cout << RED_START << "PresidentialPardonForm: constructor called with "
              << *this << COLOR_END << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << RED_START << "PresidentialPardonForm: Copy constructor"
              << COLOR_END << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
    std::cout << RED_START << "PresidentialPardonForm: Copy assignment"
              << COLOR_END << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << RED_START << "PresidentialPardonForm: Destructor called for "
              << this->getName()
              << " (signed: " << (this->getIsSigned() ? "true" : "false")
              << ", sign grade: " << this->getGradeRequiredToSign()
              << ", execute grade: " << this->getGradeRequiredToExecute() << ")"
              << " target: " << this->_target << COLOR_END << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    // 実行権限がない場合、例外をthrowする
    AForm::isExecutable(executor);

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}
