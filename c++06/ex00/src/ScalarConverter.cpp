/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:12:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/20 02:07:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include "ConversionUtils.hpp"

void ScalarConverter::convert(const char *str) {
    std::string input(str);
    std::string type = ConversionUtils::determineType(input);

    if (type == "string") {
        std::cout << "エラー: 入力は文字(char), 整数(int), 浮動小数点(float, "
                     "double)のいずれかでなければなりません。"
                  << std::endl;
        return;
    } else if (type == "overflow") {
        std::cout << "エラー: 入力値が整数型(int)の範囲を超えています。"
                  << std::endl;
        return;
    }

    // 有効な型で変換処理を実行
    ConversionUtils::toChar(input, type);
    ConversionUtils::toInt(input, type);
    ConversionUtils::toDouble(input, type);
    ConversionUtils::toFloat(input, type);
}
