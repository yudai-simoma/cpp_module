/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:37:30 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 01:35:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

const std::string Cat::CAT_TYPE = "Cat";

Cat::Cat() : Animal() {
    this->setType(Cat::CAT_TYPE);
    std::cout << RED_START << "Cat: Default constructor" << COLOR_END
              << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << RED_START << "Cat: Copy constructor" << COLOR_END << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << RED_START << "Cat: Copy assignment" << COLOR_END << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << RED_START << "Cat: Destructor" << COLOR_END << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}
