/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:46:19 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/23 02:56:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->setName("");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << RED_START << "ScavTrap object created" << COLOR_END
              << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << RED_START << "ScavTrap " << name << " is created" << COLOR_END
              << std::endl;
}

// 暗黙的にClapTrapへキャストされる
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << RED_START << "ScavTrap " << this->getName()
              << " is Copy constructor created" << COLOR_END << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << RED_START << "ScavTrap " << this->getName()
              << " is Copy assignment operator called" << COLOR_END
              << std::endl;
    return *this;
}

// 継承しているため、ClapTrapのデストラクターも自動で走る。
ScavTrap::~ScavTrap() {
    std::cout << RED_START << "ScavTrap " << this->getName() << " is destroyed"
              << COLOR_END << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() > 0) {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target
                  << ", causing " << this->getAttackDamage()
                  << " points of damage!" << std::endl;
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    } else {
        std::cout << "ScavTrap " << this->getName()
                  << " is out of energy and cannot attack!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName()
              << " is now in Gate keeper mode!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& scavTrap) {
    os << static_cast<const ClapTrap&>(scavTrap);
    return os;
}
