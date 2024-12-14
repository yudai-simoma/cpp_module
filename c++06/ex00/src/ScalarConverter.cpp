/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:12:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/14 13:05:54 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include "Config.hpp"
#include "ConversionUtils.hpp"

int ScalarConverter::convert(const char *str) {
    std::string input(str);
    std::string type = ConversionUtils::determineType(input);

    if (type == TYPE_STRING) {
        std::cout << "Error: 入力は文字(char), 整数(int), 浮動小数点(float, "
                     "double)のいずれかでなければなりません。"
                  << std::endl;
        return EXIT_FAILURE;
    }

    // 有効な型で変換処理を実行
    ConversionUtils::toChar(input, type);
    ConversionUtils::toInt(input, type);
    ConversionUtils::toFloat(input, type);
    ConversionUtils::toDouble(input, type);
    return EXIT_SUCCESS;
}
