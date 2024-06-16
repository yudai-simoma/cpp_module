/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:29:01 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/16 23:02:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0), _scalingFactor(calculateScalingFactor()) {
}

Fixed::Fixed(const int n)
    : _rawBits(n * calculateScalingFactor()),
      _scalingFactor(calculateScalingFactor()) {
}

Fixed::Fixed(const float f)
    : _rawBits(static_cast<int>(roundf(f * calculateScalingFactor()))),
      _scalingFactor(calculateScalingFactor()) {
}

Fixed::Fixed(const Fixed &other)
    : _rawBits(other.getRawBits()), _scalingFactor(other.getScalingFactor()) {
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_rawBits = other.getRawBits();
        this->_scalingFactor = other.getScalingFactor();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

int Fixed::getScalingFactor() const {
    return this->_scalingFactor;
}

float Fixed::toFloat(void) const {
    return this->_rawBits / static_cast<float>(_scalingFactor);
}

int Fixed::toInt(void) const {
    return this->_rawBits / _scalingFactor;
}

int Fixed::calculateScalingFactor(void) const {
    int x = 1;
    for (int i = 0; i < _FRACTIONAL_BITS; i++) {
        x *= 2;
    }
    return x;
}

// 比較演算子
bool Fixed::operator>(const Fixed &other) const {
    return this->_rawBits > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_rawBits < other.getRawBits();
    // return other > *this;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_rawBits >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_rawBits <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_rawBits == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_rawBits != other.getRawBits();
}

// 算術演算子
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed obj;
    if ((other.getRawBits() > 0 &&
         this->_rawBits > INT_MAX - other.getRawBits()) ||
        (other.getRawBits() < 0 &&
         this->_rawBits < INT_MIN - other.getRawBits())) {
        throw std::overflow_error("Overflow during addition");
    }
    obj.setRawBits(this->_rawBits + other.getRawBits());
    return obj;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed obj;
    if ((other.getRawBits() < 0 &&
         this->_rawBits > INT_MAX + other.getRawBits()) ||
        (other.getRawBits() > 0 &&
         this->_rawBits < INT_MIN + other.getRawBits())) {
        throw std::overflow_error("Overflow during subtraction");
    }
    obj.setRawBits(this->_rawBits - other.getRawBits());
    return obj;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed obj;
    if (other.getRawBits() != 0 &&
        this->_rawBits > INT_MAX / other.getRawBits()) {
        throw std::overflow_error("Overflow during multiplication");
    }
    obj.setRawBits((this->_rawBits * other.getRawBits()) / _scalingFactor);
    return obj;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed obj;
    if (other.getRawBits() == 0) {
        throw std::runtime_error("Division by zero");
    }
    obj.setRawBits((this->_rawBits * _scalingFactor) / other.getRawBits());
    return obj;
}

// インクリメント/デクリメント演算子
Fixed &Fixed::operator++() {
    this->_rawBits += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed obj(*this);
    this->_rawBits += 1;
    return obj;
}

Fixed &Fixed::operator--() {
    this->_rawBits -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed obj(*this);
    this->_rawBits -= 1;
    return obj;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
