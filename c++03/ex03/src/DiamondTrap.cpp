/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:53:37 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/23 03:36:05 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("") {
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(FragTrap::getAttackDamage());
    std::cout << RED_START << "DiamondTrap object created" << COLOR_END
              << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name + "_clap_name"),
      FragTrap(name + "_clap_name"),
      _name(name) {
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(FragTrap::getAttackDamage());
    std::cout << RED_START << "DiamondTrap " << name << " is created"
              << COLOR_END << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << RED_START << "DiamondTrap " << this->_name
              << " is Copy constructor created" << COLOR_END << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << RED_START << "DiamondTrap " << ClapTrap::getName()
              << " is Copy assignment operator called" << COLOR_END
              << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << RED_START << "DiamondTrap " << ClapTrap::getName()
              << " is destroyed" << COLOR_END << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name is " << this->_name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& scavTrap) {
    os << static_cast<const ClapTrap&>(scavTrap);
    return os;
}
