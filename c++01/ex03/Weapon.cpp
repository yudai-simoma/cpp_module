/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:36:38 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/09 00:57:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("") {
    std::cout << "Weapon object created" << std::endl;
}

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << type << " Weapon is created" << std::endl;
}

Weapon::~Weapon() {
    std::cout << this->_type << " Weapon is destroyed" << std::endl;
}

const std::string& Weapon::getType() const {
    return this->_type;
}

void Weapon::setType(std::string type) {
    this->_type = type;
}
