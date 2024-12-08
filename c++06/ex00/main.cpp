/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 18:29:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ConversionUtils.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: 引数の数は1つです。" << std::endl;
        return 1;
    }

    // inf, nanの対応
    int n = ConversionUtils::identifySpecialFloatValue(argv[1]);
    if (n != -1) {
        std::cout << "char: " << ConversionUtils::specialFloatValues[n][0]
                  << std::endl;
        std::cout << "int: " << ConversionUtils::specialFloatValues[n][1]
                  << std::endl;
        std::cout << "float: " << ConversionUtils::specialFloatValues[n][2]
                  << std::endl;
        std::cout << "double: " << ConversionUtils::specialFloatValues[n][3]
                  << std::endl;
        return EXIT_FAILURE;
    }
    // 4つ(char, int, float, double)の型変換
    if (ScalarConverter::convert(argv[1]) == EXIT_SUCCESS) {
        ConversionUtils::printValues();
    }
    return EXIT_SUCCESS;
}
