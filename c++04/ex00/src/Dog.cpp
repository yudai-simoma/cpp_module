/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:39:26 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 14:17:33 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

const std::string Dog::DOG_TYPE = "Dog";

Dog::Dog() : Animal() {
    this->setType(Dog::DOG_TYPE);
    std::cout << RED_START << "Dog: Default constructor" << COLOR_END
              << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << RED_START << "Dog: Copy constructor" << COLOR_END << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << RED_START << "Dog: Copy assignment" << COLOR_END << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << RED_START << "Dog: Destructor" << COLOR_END << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bowwow" << std::endl;
}
