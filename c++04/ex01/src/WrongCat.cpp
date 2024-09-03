/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 01:16:07 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/03 01:37:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

const std::string WrongCat::WRONG_CAT_TYPE = "WrongCat";

WrongCat::WrongCat() : WrongAnimal() {
    this->setType(WrongCat::WRONG_CAT_TYPE);
    std::cout << RED_START << "WrongCat: Default constructor" << COLOR_END
              << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << RED_START << "WrongCat: Copy constructor" << COLOR_END
              << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << RED_START << "WrongCat: Copy assignment" << COLOR_END
              << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << RED_START << "WrongCat: Destructor" << COLOR_END << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "meow" << std::endl;
}
