/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:17 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 15:42:33 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {
    std::cout << RED_START << "Bureaucrat: Default constructor" << COLOR_END
              << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : _name(name), _grade(grade) {
    if (grade <= 0) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade >= 151) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << RED_START
              << "Bureaucrat: constructor called with name: " << name
              << ", grade: " << grade << COLOR_END << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
    std::cout << RED_START << "Bureaucrat: Copy constructor" << COLOR_END
              << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    std::cout << RED_START << "Bureaucrat: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED_START << "Bureaucrat: Destructor called for "
              << this->_name << " (grade " << this->_grade << ")" << COLOR_END
              << std::endl;
}

std::string const& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade <= 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade >= 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade++;
}

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->_name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->_name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << "name: " << bureaucrat.getName()
       << ", grade: " << bureaucrat.getGrade();
    return os;
}
