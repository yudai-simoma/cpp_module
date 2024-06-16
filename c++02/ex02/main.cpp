/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 02:28:09 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/16 22:38:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

#include "Fixed.hpp"

int main(void) {
    // コンストラクタテスト
    Fixed a;
    Fixed b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    Fixed const e(-10);

    std::cout << "----- Constructors -----" << std::endl;
    std::cout << "a: " << a << std::endl;  // Default
    std::cout << "b: " << b << std::endl;  // Int
    std::cout << "c: " << c << std::endl;  // Float
    std::cout << "d: " << d << std::endl;  // Copy

    // 比較演算子テスト
    std::cout << "\n----- Comparison Operators -----" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a > c: " << (a > c) << std::endl;
    std::cout << "a < c: " << (a < c) << std::endl;
    std::cout << "a >= c: " << (a >= c) << std::endl;
    std::cout << "a <= c: " << (a <= c) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // 算術演算子テスト
    std::cout << "\n----- Arithmetic Operators -----" << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

    // インクリメント/デクリメント演算子テスト
    std::cout << "\n----- Increment/Decrement Operators -----" << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    // min/max関数テスト
    std::cout << "\n----- min/max Functions -----" << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
    std::cout << "min(e, b): " << Fixed::min(e, b) << std::endl;
    std::cout << "max(e, b): " << Fixed::max(e, b) << std::endl;

    return 0;
}

// PDFのmain
//  int main( void ) {
//      Fixed a;
//      Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }
