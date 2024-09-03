/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 00:06:26 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 00:49:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("") {
    std::cout << RED_START << "Animal: Default constructor" << COLOR_END
              << std::endl;
}

Animal::Animal(const Animal& other) : _type(other.getType()) {
    std::cout << RED_START << "Animal: Copy constructor" << COLOR_END
              << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->_type = other.getType();
    }
    std::cout << RED_START << "Animal: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << RED_START << "Animal: Destructor" << COLOR_END << std::endl;
}

void Animal::makeSound() const {
    std::cout << "growl..." << std::endl;
}

const std::string& Animal::getType() const {
    return this->_type;
}

void Animal::setType(const std::string& type) {
    this->_type = type;
}
