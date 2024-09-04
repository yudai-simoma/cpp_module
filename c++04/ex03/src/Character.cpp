/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:59:33 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/04 23:11:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(""){
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->_materia[i] = NULL;
	}
	std::cout << RED_START << "Character: Default constructor" << COLOR_END << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->_materia[i] = NULL;
	}
	std::cout << RED_START << "Character: constructor called with name: " << name << COLOR_END << std::endl;
}

Character::Character(Character& other) : _name(other._name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->_materia[i] = other._materia[i]->clone();
	}
    std::cout << RED_START << "Character: Copy constructor" << COLOR_END << std::endl;
}

// ここから始める
Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->_name = other._name;
	}
    std::cout << RED_START << "Character: Copy assignment" << COLOR_END << std::endl;
	return *this;
}

Character::~Character() {
    std::cout << RED_START << "Character: Destructor" << COLOR_END << std::endl;
}

std::string const & Character::getName() const {

}

void Character::equip(AMateria* m) {

}

void Character::unequip(int idx) {

}

void Character::use(int idx, Character& target) {
	
}
