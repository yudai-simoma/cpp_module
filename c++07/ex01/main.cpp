/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:56:38 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/15 23:32:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

// 通常の関数
void print_int(int value) {
    std::cout << value << std::endl;
}

// 関数テンプレート
template <typename T>
void print_element(T value) {
    std::cout << value << std::endl;
}

int main() {
    // int型の配列のテスト
    std::cout << "--- int array test ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intLength, print_int);

    // double型の配列のテスト
    std::cout << "--- double array test ---" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
    iter(doubleArray, doubleLength, print_element<double>);

    // string型の配列のテスト
    std::cout << "--- string array test ---" << std::endl;
    std::string strArray[] = {"apple", "banana", "cherry"};
    size_t strLength = sizeof(strArray) / sizeof(strArray[0]);
    iter(strArray, strLength, print_element<std::string>);

    return 0;
}
