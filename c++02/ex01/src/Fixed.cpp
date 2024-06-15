/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:29:01 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/15 19:10:58 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _rawBits(0) {
    setRawBits(n * calculateScalingFactor());
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _rawBits(0) {
    setRawBits(static_cast<int>(roundf(f * calculateScalingFactor())));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
    return this->_rawBits / static_cast<float>(calculateScalingFactor());
}

int Fixed::toInt(void) const {
    return this->_rawBits / calculateScalingFactor();
}

int Fixed::calculateScalingFactor() const {
    int x = 1;
    for (int i = 0; i < _FRACTIONAL_BITS; i++) {
        x *= 2;
    }
    return x;
}
