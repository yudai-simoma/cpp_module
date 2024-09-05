/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:55:07 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 11:36:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

const std::string Ice::ICE_TYPE = "ice";

Ice::Ice() {
	this->setType(Ice::ICE_TYPE);
	std::cout << RED_START << "Ice: Default constructor" << COLOR_END << std::endl;
}

Ice::Ice(Ice& other) : AMateria(other) {
    std::cout << RED_START << "Ice: Copy constructor" << COLOR_END << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
    std::cout << RED_START << "Ice: Copy assignment" << COLOR_END << std::endl;
	return *this;
}

Ice::~Ice() {
    std::cout << RED_START << "Ice: Destructor" << COLOR_END << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
