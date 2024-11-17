/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:55:54 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 17:00:14 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("", this->GRADE_REQUIRED_TO_SIGN, this->GRADE_REQUIRED_TO_EXECUTE),
      _target("") {
    std::cout << RED_START << "ShrubberyCreationForm: Default constructor"
              << COLOR_END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target,
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
    std::cout << RED_START << "ShrubberyCreationForm: constructor called with "
              << *this << COLOR_END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
    std::cout << RED_START << "ShrubberyCreationForm: Copy constructor"
              << COLOR_END << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
    std::cout << RED_START << "ShrubberyCreationForm: Copy assignment"
              << COLOR_END << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << RED_START << "ShrubberyCreationForm: Destructor called for "
              << this->getName()
              << " (signed: " << (this->getIsSigned() ? "true" : "false")
              << ", sign grade: " << this->getGradeRequiredToSign()
              << ", execute grade: " << this->getGradeRequiredToExecute() << ")"
              << " target: " << this->_target << COLOR_END << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    // 実行権限がない場合、例外をthrowする
    AForm::isExecutable(executor);
    // 出力ファイル名を作成
    std::string filename = this->_target + "_shrubbery";
    // ファイルを開く
    std::ofstream file(filename.c_str());

    // ファイルが開けなかった場合の処理
    if (!file) {
        std::cout << "Failed to create the file." << std::endl;
        return;
    }

    // ASCII アートの木をファイルに書き込む
    file << "        ^  " << std::endl;
    file << "       ^^^ " << std::endl;
    file << "      ^^^^^" << std::endl;
    file << "     ^^^^^^^" << std::endl;
    file << "    ^^^^^^^^^" << std::endl;
    file << "   ^^^^^^^^^^^" << std::endl;
    file << "        |  " << std::endl;
    file << "        |  " << std::endl;

    file.close();  // ファイルを閉じる

    std::cout << "Created a file " << filename << " with ASCII trees."
              << std::endl;
}
