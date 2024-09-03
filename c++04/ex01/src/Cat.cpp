/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:37:30 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 14:15:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

const std::string Cat::CAT_TYPE = "Cat";

Cat::Cat() : Animal() {
    this->setType(Cat::CAT_TYPE);
    std::cout << RED_START << "Cat: Default constructor" << COLOR_END
              << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << RED_START << "Cat: Copy constructor" << COLOR_END << std::endl;
    this->brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << RED_START << "Cat: Copy assignment" << COLOR_END << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        this->brain = new Brain(*(other.brain));
    }
    return *this;
}

Cat::~Cat() {
    delete(this->brain);
    std::cout << RED_START << "Cat: Destructor" << COLOR_END << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow" << std::endl;
}

std::string Cat::getIdea(int index) const {
	return this->brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string& idea) {
	this->brain->setIdea(index, idea);
}
