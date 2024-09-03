/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:39:26 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 19:38:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

const std::string Dog::DOG_TYPE = "Dog";

Dog::Dog() : Animal() {
    this->setType(Dog::DOG_TYPE);
    std::cout << RED_START << "Dog: Default constructor" << COLOR_END
              << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << RED_START << "Dog: Copy constructor" << COLOR_END << std::endl;
    this->brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << RED_START << "Dog: Copy assignment" << COLOR_END << std::endl;
    if (this != &other) {
        delete this->brain;
        Animal::operator=(other);
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << RED_START << "Dog: Destructor" << COLOR_END << std::endl;
}

void Dog::makeSound() const {
    std::cout << "bowwow" << std::endl;
}

std::string Dog::getIdea(int index) const {
    return this->brain->getIdea(index);
}

void Dog::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}
