/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:36:02 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/09 01:01:32 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
    std::cout << this->_name << " is created" << std::endl;
}

HumanB::~HumanB() {
    std::cout << this->_name << " is destroyed" << std::endl;
}

// <name> attacks with their <weapon type>
void HumanB::attack() {
    if (this->_weapon == NULL) {
        std::cout << this->_name << " no weapon" << std::endl;
        return;
    }

    std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}
