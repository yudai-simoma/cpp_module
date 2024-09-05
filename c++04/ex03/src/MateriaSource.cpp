/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:14:53 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 11:44:41 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->_materias[i] = NULL;
	}
	std::cout << RED_START << "MateriaSource: Default constructor" << COLOR_END << std::endl;
}

MateriaSource::MateriaSource(MateriaSource& other) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		delete this->_materias[i];
		this->_materias[i] = other._materias[i]->clone();
	}
    std::cout << RED_START << "MateriaSource: Copy constructor" << COLOR_END << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < MAX_MATERIA; i++) {
			delete this->_materias[i];
			this->_materias[i] = other._materias[i]->clone();
		}
	}
    std::cout << RED_START << "MateriaSource: Copy assignment" << COLOR_END << std::endl;
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		delete this->_materias[i];
	}
    std::cout << RED_START << "MateriaSource: Destructor" << COLOR_END << std::endl;
}

// TODO: 処理があっているか？
void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] == NULL) {
			this->_materias[i] = m;
			break;
		}
	}
}

// TODO: 処理があっているか？
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}
