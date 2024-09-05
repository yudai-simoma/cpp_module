/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:14:53 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 17:00:44 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < MAX_MATERIA; i++) {
        this->_materias[i] = NULL;
    }
    std::cout << RED_START << "MateriaSource: Default constructor" << COLOR_END
              << std::endl;
}

MateriaSource::MateriaSource(MateriaSource& other) {
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (other._materias[i] != NULL) {
            delete this->_materias[i];
            this->_materias[i] = other._materias[i]->clone();
        } else {
            this->_materias[i] = NULL;
        }
    }
    std::cout << RED_START << "MateriaSource: Copy constructor" << COLOR_END
              << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < MAX_MATERIA; i++) {
            if (other._materias[i] != NULL) {
                delete this->_materias[i];
                this->_materias[i] = other._materias[i]->clone();
            } else {
                this->_materias[i] = NULL;
            }
        }
    }
    std::cout << RED_START << "MateriaSource: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (this->_materias[i] != NULL) {
            delete this->_materias[i];
        }
    }
    std::cout << RED_START << "MateriaSource: Destructor" << COLOR_END
              << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (this->_materias[i] == NULL) {
            this->_materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < MAX_MATERIA; i++) {
        if (this->_materias[i] != NULL &&
            this->_materias[i]->getType() == type) {
            return this->_materias[i]->clone();
        }
    }
    return NULL;
}
