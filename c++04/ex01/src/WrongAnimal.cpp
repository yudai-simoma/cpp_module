/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:15:49 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 01:16:37 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("") {
    std::cout << RED_START << "WrongAnimal: Default constructor" << COLOR_END
              << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other.getType()) {
    std::cout << RED_START << "WrongAnimal: Copy constructor" << COLOR_END
              << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        this->_type = other.getType();
    }
    std::cout << RED_START << "WrongAnimal: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << RED_START << "WrongAnimal: Destructor" << COLOR_END
              << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "growl..." << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::setType(const std::string& type) {
    this->_type = type;
}
