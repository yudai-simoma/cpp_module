/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:59:33 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 17:00:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(""){
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->_materias[i] = NULL;
	}
	std::cout << RED_START << "Character: Default constructor" << COLOR_END << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->_materias[i] = NULL;
	}
	std::cout << RED_START << "Character: constructor called with name: " << name << COLOR_END << std::endl;
}

Character::Character(Character& other) : _name(other._name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] != NULL) {
			delete this->_materias[i];
		}
		if (other._materias[i] != NULL) {
			this->_materias[i] = other._materias[i]->clone();
		} else {
			this->_materias[i] = NULL;
		}
	}
    std::cout << RED_START << "Character: Copy constructor" << COLOR_END << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < MAX_MATERIA; i++) {
			if (this->_materias[i] != NULL) {
				delete this->_materias[i];
			}
			if (other._materias[i] != NULL) {
				this->_materias[i] = other._materias[i]->clone();
			} else {
				this->_materias[i] = NULL;
			}
		}
	}
    std::cout << RED_START << "Character: Copy assignment" << COLOR_END << std::endl;
	return *this;
}

Character::~Character() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] != NULL) {
			delete this->_materias[i];
		}
	}
    std::cout << RED_START << "Character: Destructor" << COLOR_END << std::endl;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			break;
		}
	}
}

void Character::unequip(int	 idx) {
	if (idx >= 0 && idx < MAX_MATERIA) {
		this->_materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if ((idx >= 0 && idx < MAX_MATERIA) && this->_materias[idx] != NULL) {
		this->_materias[idx]->use(target);
	}
}

std::string const & Character::getName() const {
	return this->_name;
}
