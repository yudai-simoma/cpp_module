/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:43:30 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/04 15:54:24 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

const std::string Cure::CURE_TYPE = "cure";

Cure::Cure() {
	this->setType(Cure::CURE_TYPE);
	std::cout << RED_START << "Cure: Default constructor" << COLOR_END << std::endl;
}

Cure::Cure(Cure& other) : AMateria(other) {
    std::cout << RED_START << "Cure: Copy constructor" << COLOR_END << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
    std::cout << RED_START << "Cure: Copy assignment" << COLOR_END << std::endl;
	return *this;
}

Cure::~Cure() {
    std::cout << RED_START << "Cure: Destructor" << COLOR_END << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
