/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:44:19 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/13 00:44:19 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("") {
    std::cout << "Zombie object created" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    std::cout << this->_name << " is created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->_name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
}

void Zombie::announce() {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
