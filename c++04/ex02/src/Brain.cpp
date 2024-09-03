/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 02:46:00 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 03:14:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < MAX_IDEAS; i++) {
        _ideas[i] = "";
    }
    std::cout << RED_START << "Brain: Default constructor" << COLOR_END
              << std::endl;
}

Brain::Brain(Brain& other) {
    for (int i = 0; i < MAX_IDEAS; i++) {
        this->_ideas[i] = other.getIdea(i);
    }
    std::cout << RED_START << "Brain: Copy constructor" << COLOR_END
              << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < MAX_IDEAS; i++) {
            this->_ideas[i] = other.getIdea(i);
        }
    }
    std::cout << RED_START << "Brain: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << RED_START << "Brain: Destructor" << COLOR_END << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= MAX_IDEAS)
        std::cout << "Error: Invalid idea index: " << index << std::endl;
    return this->_ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= MAX_IDEAS)
        std::cout << "Error: Invalid idea index: " << index << std::endl;
    this->_ideas[index] = idea;
}
