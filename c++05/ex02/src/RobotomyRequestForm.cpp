/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:00:51 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 18:56:58 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", this->GRADE_REQUIRED_TO_SIGN, this->GRADE_REQUIRED_TO_EXECUTE), _target("") {
    std::cout << RED_START << "RobotomyRequestForm: Default constructor" << COLOR_END
              << std::endl;
    this->initialize();
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target, std::string const& name, int gradeRequiredToSign, int gradeRequiredToExecute)
	: AForm(name, gradeRequiredToSign, gradeRequiredToExecute), _target(target) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeRequiredToSign > this->GRADE_REQUIRED_TO_SIGN || gradeRequiredToExecute > this->GRADE_REQUIRED_TO_EXECUTE) {
        throw AForm::GradeTooLowException();
    }
    std::cout << RED_START << "RobotomyRequestForm: constructor called with " << *this
              << COLOR_END << std::endl;
    this->initialize();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
    std::cout << RED_START << "RobotomyRequestForm: Copy constructor" << COLOR_END << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << RED_START << "RobotomyRequestForm: Copy assignment" << COLOR_END << std::endl;
	if (this != &other) {
		AForm::operator=(other);
        this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << RED_START << "RobotomyRequestForm: Destructor called for " << this->getName()
              << " (signed: " << (this->getIsSigned() ? "true" : "false")
              << ", sign grade: " << this->getGradeRequiredToSign()
              << ", execute grade: " << this->getGradeRequiredToExecute() << ")"
              << " target: " << this->_target
              << COLOR_END << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	// 実行権限がない場合、例外をthrowする
	AForm::isExecutable(executor);

    // ドリルのような音
    std::cout << "brrrrrrr......" << std::endl;

    // 成功率が50%であることを模擬
    // 0 または 1 をランダムに生成
    int success = rand() % 2;

    if (success) {
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy on " << this->_target << " failed." << std::endl;
    }
}

void RobotomyRequestForm::initialize() {
    // 乱数の初期化
    srand(static_cast<unsigned int>(time(0)));
}
