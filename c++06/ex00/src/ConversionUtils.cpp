/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionUtils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:18:05 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/08 17:55:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConversionUtils.hpp"

char ConversionUtils::c = '\0';
int ConversionUtils::intNum = 0;
double ConversionUtils::doubleNum = 0.0;
float ConversionUtils::floatNum = 0.0f;

#include <cctype>
#include <climits>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>

void ConversionUtils::printValues() {
    if (std::isprint(ConversionUtils::getC())) {
        std::cout << "char: '" << ConversionUtils::getC() << "'" << std::endl;
    } else if (ConversionUtils::getIntNum() >= 0 && ConversionUtils::getIntNum() <= 255) {
    // } else if (ConversionUtils::getIntNum() <= INT_MIN && ConversionUtils::getIntNum() <= INT_MAX) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    std::cout << "int: " << ConversionUtils::getIntNum() << std::endl;

    float floatNum = ConversionUtils::getFloatNum();
    // 条件に応じて出力形式を切り替える
    if (std::abs(floatNum) >= 1e+6 || (floatNum != 0.0 && std::abs(floatNum) < 1e-6)) {
        // 小数点以下5桁に設定
        std::cout << std::fixed << std::setprecision(5);
        // 指数表記で出力する設定
        std::cout << std::scientific;
    } else {
        // 小数点以下1桁に設定
        std::cout << std::fixed << std::setprecision(1);
    }
    std::cout << "float: " << floatNum << "f" << std::endl;

    double doubleNum = ConversionUtils::getDoubleNum();
    // doubleも同様に出力形式を切り替える
    if (std::abs(doubleNum) >= 1e+6 || (doubleNum != 0.0 && std::abs(doubleNum) < 1e-6)) {
        // 小数点以下5桁に設定
        std::cout << std::fixed << std::setprecision(5);
        // 指数表記で出力する設定
        std::cout << std::scientific;
    } else {
        std::cout << std::fixed << std::setprecision(1);
    }
    std::cout << "double: " << ConversionUtils::getDoubleNum() << std::endl;
}

int ConversionUtils::identifySpecialFloatValue(const char *str) {
    std::string input(str);

    if (input == "inf") {
        return 0;
    } else if (input == "+inf") {
        return 1;
    } else if (input == "-inf") {
        return 2;
    } else if (input == "inff") {
        return 3;
    } else if (input == "+inff") {
        return 4;
    } else if (input == "-inff") {
        return 5;
    } else if (input == "nan") {
        return 6;
    } else if (input == "+nan") {
        return 7;
    } else if (input == "-nan") {
        return 8;
    } else if (input == "nanf") {
        return 9;
    } else if (input == "+nanf") {
        return 10;
    } else if (input == "-nanf") {
        return 11;
    } else {
        return -1;
    }
}

// メインの判定関数
std::string ConversionUtils::determineType(const std::string &input) {
    if (ConversionUtils::isEmpty(input)) {
        return "string";
    }

    if (ConversionUtils::isSingleChar(input)) {
        return "char";
    }

    long intValue;
    if (ConversionUtils::isInteger(input, intValue)) {
        if (intValue >= std::numeric_limits<int>::min() && intValue <= std::numeric_limits<int>::max()) {
            return "int";
        } else {
            return "overflow";
        }
    }

    bool endsWithF;
    if (ConversionUtils::isFloatingPoint(input, endsWithF)) {
        // 浮動小数点型の場合
        double value = std::strtod(input.c_str(), NULL);
        // オーバーフロー/アンダーフローチェックをdoubleの範囲で行う
        if (value > INT_MAX) {
            return "overflow";
        } else if (value < INT_MIN) {
            return "overflow";
        } else {
            return endsWithF ? "float" : "double";
        }
    }

    return "string";
}

void ConversionUtils::toChar(const std::string input, const std::string &type) {
    if (type == "char") {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setC(input[0]);
            return;
        }
    } else if (type == "int") {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
        // ASCII範囲内の値か確認
        if (value >= 0 && value <= 255) {
            ConversionUtils::setC(static_cast<char>(value));
            return;
        }
    } else if (type == "float" || type == "double") {
        // 浮動小数点型の場合
        double value = std::strtod(input.c_str(), NULL);
        // ASCII範囲内の値か確認
        if (value >= 0.0 && value <= 255.0) {
            ConversionUtils::setC(static_cast<char>(value));
            return;
        }
    }
    
    // 変換できない場合
    // 空文字列を意味するNULL文字を設定
    ConversionUtils::setC('\0');
}

void ConversionUtils::toInt(const std::string input, const std::string &type) {
    if (type == "char") {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setIntNum(static_cast<int>(input[0]));
            return;
        }
    } else if (type == "int") {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
        if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
            ConversionUtils::setIntNum(static_cast<int>(value));
            return;
        }
    } else if (type == "float" || type == "double") {
        // 浮動小数点型の場合
        double value = std::strtod(input.c_str(), NULL);
        // オーバーフロー/アンダーフローチェックをdoubleの範囲で行う
        if (value > std::numeric_limits<int>::max()) {
            ConversionUtils::setIntNum(std::numeric_limits<int>::max());
            return;
        } else if (value < std::numeric_limits<int>::min()) {
            ConversionUtils::setIntNum(std::numeric_limits<int>::min());
            return;
        } else {
            ConversionUtils::setIntNum(static_cast<int>(value));
            return;
        }
    }

    // 変換できない場合
    ConversionUtils::setIntNum(0);
}

void ConversionUtils::toFloat(const std::string input,
                               const std::string &type) {
    if (type == "char") {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setFloatNum(static_cast<float>(input[0]));
            return;
        }
    } else if (type == "int") {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
        if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
            ConversionUtils::setFloatNum(static_cast<float>(value));
            return;
        }
    } else if (type == "float" || type == "double") {
        // 浮動小数点型の場合
        char *endPtr;
        double value = std::strtod(input.c_str(), &endPtr);
        if (*endPtr == 'f' || *endPtr == '\0') { // 'f' (float) または終端文字
            ConversionUtils::setDoubleNum(value);
            return;
        }
    }

    // 変換できない場合
    ConversionUtils::setFloatNum(0.0f);
}

void ConversionUtils::toDouble(const std::string input,
                                const std::string &type) {
    if (type == "char") {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setDoubleNum(static_cast<double>(input[0]));
            return;
        }
    } else if (type == "int") {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
        if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
            ConversionUtils::setDoubleNum(static_cast<double>(value));
            return;
        }
    } else if (type == "float" || type == "double") {
        // 浮動小数点型の場合
        char *endPtr;
        double value = std::strtod(input.c_str(), &endPtr);
        if (*endPtr == 'f' || *endPtr == '\0') { // 'f' (float) または終端文字
            ConversionUtils::setFloatNum(static_cast<float>(value));
            return;
        }
    }

    // 変換できない場合
    ConversionUtils::setDoubleNum(0.0);
}

// 空文字列チェック
bool ConversionUtils::isEmpty(const std::string &input) {
    return input.empty();
}

// 1文字の文字型チェック
bool ConversionUtils::isSingleChar(const std::string &input) {
    return input.length() == 1 && !std::isdigit(input[0]);
}

// 整数チェック
bool ConversionUtils::isInteger(const std::string &input, long &value) {
    if (input.empty()) {
        return false;
    }

    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isdigit(input[i]) &&
            !(i == 0 && (input[i] == '-' || input[i] == '+'))) {
            return false;
        }
    }

    char *endPtr;
    value = std::strtoll(input.c_str(), &endPtr, 10);
    return *endPtr == '\0';
}

// 浮動小数点数チェック
bool ConversionUtils::isFloatingPoint(const std::string &input,
                                      bool &endsWithF) {
    if (input.empty()) {
        return false;
    }

    std::string trimmedInput = input;
    size_t length = input.length();

    // f/Fが末尾にある場合を処理
    if (length > 1 && (input[length - 1] == 'f' || input[length - 1] == 'F')) {
        endsWithF = true;
        trimmedInput = input.substr(0, length - 1);
    } else {
        endsWithF = false;
    }

    bool hasDot = false, hasE = false;

    for (size_t i = 0; i < trimmedInput.length(); ++i) {
        if (trimmedInput[i] == '.') {
            // ドットが複数
            if (hasDot) {
                return false;
            }
            hasDot = true;
        } else if (trimmedInput[i] == 'e' || trimmedInput[i] == 'E') {
            // e/Eが不正な位置
            if (hasE || i == 0 || i == trimmedInput.length() - 1) {
                return false;
            }
            hasE = true;

            // 符号のスキップ
            if (i + 1 < trimmedInput.length() &&
                (trimmedInput[i + 1] == '+' || trimmedInput[i + 1] == '-')) {
                ++i;
            }
        } else if (!std::isdigit(trimmedInput[i]) &&
                   !(i == 0 &&
                     (trimmedInput[i] == '-' || trimmedInput[i] == '+'))) {
            // 不正な文字
            return false;
        }
    }

    //trimmedInputが浮動小数点数の構文に正しく含まれているか確認
    // 変換処理がどこで停止したかをこのポインタに格納します。
    char *endPtr;
    std::strtod(trimmedInput.c_str(), &endPtr);
    return *endPtr == '\0';
}

// 特殊値 (inf, nan) のチェック
bool ConversionUtils::isSpecialFloatingPoint(const std::string &input) {
    return input == "inf" || input == "+inf" || input == "-inf" ||
           input == "infinity" || input == "+infinity" ||
           input == "-infinity" || input == "nan" || input == "+nan" ||
           input == "-nan";
}

char ConversionUtils::getC() {
    return c;
}

void ConversionUtils::setC(char a) {
    c = a;
}

int ConversionUtils::getIntNum() {
    return intNum;
}

void ConversionUtils::setIntNum(int num) {
    intNum = num;
}

double ConversionUtils::getDoubleNum() {
    return doubleNum;
}

void ConversionUtils::setDoubleNum(double num) {
    doubleNum = num;
}

float ConversionUtils::getFloatNum() {
    return floatNum;
}

void ConversionUtils::setFloatNum(float num) {
    floatNum = num;
}

const char* ConversionUtils::specialFloatValues[12][4] = {
    {"impossible", "impossible", "inff", "inf"},
    {"impossible", "impossible", "+inff", "+inf"},
    {"impossible", "impossible", "-inff", "-inf"},
    {"impossible", "impossible", "inff", "inf"},
    {"impossible", "impossible", "+inff", "+inf"},
    {"impossible", "impossible", "-inff", "-inf"},
    {"impossible", "impossible", "nanf", "nan"},
    {"impossible", "impossible", "+nanf", "+nan"},
    {"impossible", "impossible", "-nanf", "-nan"},
    {"impossible", "impossible", "nanf", "nan"},
    {"impossible", "impossible", "+nanf", "+nan"},
    {"impossible", "impossible", "-nanf", "-nan"},
};
