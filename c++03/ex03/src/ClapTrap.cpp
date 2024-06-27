/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:06:45 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/27 21:44:15 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << RED_START << "ClapTrap object created" << COLOR_END
              << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << RED_START << "ClapTrap " << this->_name << " is created"
              << COLOR_END << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other.getName()),
      _hitPoints(other.getHitPoints()),
      _energyPoints(other.getEnergyPoints()),
      _attackDamage(other.getAttackDamage()) {
    std::cout << RED_START << "ClapTrap " << this->_name
              << " is Copy constructor created" << COLOR_END << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other.getName();
        this->_hitPoints = other.getHitPoints();
        this->_energyPoints = other.getEnergyPoints();
        this->_attackDamage = other.getAttackDamage();
    }
    std::cout << RED_START << "ClapTrap " << this->_name
              << " is Copy assignment operator called" << COLOR_END
              << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << RED_START << "ClapTrap " << this->_name << " is destroyed"
              << COLOR_END << std::endl;
}

/**
 * この関数は、ClapTrapがtargetに攻撃を仕掛け、targetのヒットポイントをattack
 * damage分減らします
 */
void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target
                  << ", causing " << this->_attackDamage << " points of damage!"
                  << std::endl;
        --this->_energyPoints;
    } else {
        std::cout << "ClapTrap " << this->_name
                  << " is out of energy and cannot attack!" << std::endl;
    }
}

/**
 * この関数は、ClapTrapがamount分のダメージを受けます。
 */
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " takes " << amount
                << " points of damage! Ouch!" << std::endl;

        if (amount > this->_hitPoints) {
            this->_hitPoints = 0;
        } else {
            this->_hitPoints -= amount;
        }
    } else {
        std::cout << "ClapTrap " << this->_name
                  << " is out of energy and cannot takeDamage!" << std::endl;
    }
}

/**
 * この関数は、ClapTrapのヒットポイントをamount分回復します。
 */
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " repaired itself for "
                  << amount << " hit points! Feeling better!" << std::endl;
        --this->_energyPoints;

        if (this->_hitPoints + amount < this->_hitPoints) {
            this->_hitPoints = UINT_MAX;
        } else {
            this->_hitPoints += amount;
        }
    } else {
        std::cout << "ClapTrap " << this->_name
                  << " is out of energy and cannot beRepaired!" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap) {
    os << "name: " << clapTrap.getName()
       << ", hitPoints: " << clapTrap.getHitPoints()
       << ", energyPoints: " << clapTrap.getEnergyPoints()
       << ", attackDamage: " << clapTrap.getAttackDamage();
    return os;
}

const std::string& ClapTrap::getName() const {
    return this->_name;
}

void ClapTrap::setName(const std::string& name) {
    this->_name = name;
}

int ClapTrap::getHitPoints() const {
    return this->_hitPoints;
}

void ClapTrap::setHitPoints(const int hitPoints) {
    this->_hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return this->_energyPoints;
}

void ClapTrap::setEnergyPoints(const int energyPoints) {
    this->_energyPoints = energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return this->_attackDamage;
}

void ClapTrap::setAttackDamage(const int attackDamage) {
    this->_attackDamage = attackDamage;
}
