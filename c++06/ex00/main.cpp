/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/20 10:03:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <iomanip>

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

    std::cout << std::fixed << std::setprecision(1); // 小数点以下1桁に設定

    std::cout << "char: " << ConversionUtils::getC() << std::endl;
    std::cout << "int: " << ConversionUtils::getIntNum() << std::endl;
    std::cout << "double: " << ConversionUtils::getDoubleNum() << std::endl;
    std::cout << "float: " << ConversionUtils::getFloatNum() << std::endl;

    ScalarConverter::convert(argv[1]);

    std::cout << "char: " << ConversionUtils::getC() << std::endl;
    std::cout << "int: " << ConversionUtils::getIntNum() << std::endl;
    std::cout << "double: " << ConversionUtils::getDoubleNum() << std::endl;
    std::cout << "float: " << ConversionUtils::getFloatNum() << std::endl;
    return 0;
}
