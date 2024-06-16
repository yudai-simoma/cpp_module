/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 22:36:22 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/16 23:01:45 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <cmath>
#include <iostream>

class Fixed {
   public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    int getScalingFactor(void) const;
    float toFloat(void) const;
    int toInt(void) const;
    int calculateScalingFactor(void) const;

    // 比較演算子
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // 算術演算子
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // インクリメント/デクリメント演算子
    Fixed &operator++();    // 前置インクリメント
    Fixed operator++(int);  // 後置インクリメント
    Fixed &operator--();
    Fixed operator--(int);

    // min/max関数テスト
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

   private:
    static const int _FRACTIONAL_BITS = 8;
    int _rawBits;
    int _scalingFactor;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
