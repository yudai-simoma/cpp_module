/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:35:59 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/09 01:02:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
    std::cout << name << " is created" << std::endl;
}

HumanA::~HumanA() {
    std::cout << this->_name << " is destroyed" << std::endl;
}

void HumanA::attack() {
    std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}
