/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:15:02 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 20:28:16 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << RED_START << "Intern: Default constructor" << COLOR_END
              << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << RED_START << "Intern: Copy constructor" << COLOR_END
              << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << RED_START << "Intern: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << RED_START << "Intern: Destructor called" << COLOR_END
              << std::endl;
}

AForm* Intern::makeForm(std::string const& formName,
                        std::string const& target) {
    std::string formNames[NUM_FORMS] = {
        "robotomy request", "presidential pardon", "shrubbery creation"};

    int i = 0;
    for (; i < NUM_FORMS; i++) {
        if (formNames[i] == formName) {
            break;
        }
    }
    switch (i) {
        case RobotomyRequest:
            return new RobotomyRequestForm(
                target, formName, RobotomyRequestForm::GRADE_REQUIRED_TO_SIGN,
                RobotomyRequestForm::GRADE_REQUIRED_TO_EXECUTE);
        case PresidentialPardon:
            return new PresidentialPardonForm(
                target, formName,
                PresidentialPardonForm::GRADE_REQUIRED_TO_SIGN,
                PresidentialPardonForm::GRADE_REQUIRED_TO_EXECUTE);
        case ShrubberyCreation:
            return new ShrubberyCreationForm(
                target, formName, ShrubberyCreationForm::GRADE_REQUIRED_TO_SIGN,
                ShrubberyCreationForm::GRADE_REQUIRED_TO_EXECUTE);
        default:
            std::cout << "Invalid form name: " << formName << std::endl;
            return NULL;  // または nullptr
    }
}
