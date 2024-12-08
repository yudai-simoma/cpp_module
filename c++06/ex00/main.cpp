/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 16:59:59 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "ConversionUtils.hpp"
#include "ScalarConverter.hpp"

/*
・型の判断
・型を変換
・その他の方にキャスト

ScalarConverter
    static convert()
namespace
    判断
    出力
    intの変換
    doubleの変換
    floatの変換
*/
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: 引数の数は1つです。" << std::endl;
        return 1;
    }

    int n = ConversionUtils::identifySpecialFloatValue(argv[1]);
    if (n != -1) {
        std::cout << "char: " << ConversionUtils::specialFloatValues[n][0] << std::endl;
        std::cout << "int: " << ConversionUtils::specialFloatValues[n][1] << std::endl;
        std::cout << "float: " << ConversionUtils::specialFloatValues[n][2] << std::endl;
        std::cout << "double: " << ConversionUtils::specialFloatValues[n][3] << std::endl;
        return 1;
    }
    if (ScalarConverter::convert(argv[1]) == 0) {
        ConversionUtils::printValues();
    }
    return 0;
}
