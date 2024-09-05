/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:26:33 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 11:26:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("") {
	std::cout << RED_START << "AMateria: Default constructor" << COLOR_END << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type) {
	std::cout << RED_START << "AMateria: constructor called with type: " << type << COLOR_END << std::endl;
}

AMateria::AMateria(AMateria& other): _type(other._type) {
    std::cout << RED_START << "AMateria: Copy constructor" << COLOR_END << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
    std::cout << RED_START << "AMateria: Copy assignment" << COLOR_END << std::endl;
	return *this;
}

AMateria::~AMateria() {
    std::cout << RED_START << "AMateria: Destructor" << COLOR_END << std::endl;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria::use() called on " << target.getName() << std::endl;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::setType(const std::string type) {
	this->_type = type;
}
