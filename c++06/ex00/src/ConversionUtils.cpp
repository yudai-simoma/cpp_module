/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionUtils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:18:05 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/14 13:04:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConversionUtils.hpp"

#include "Config.hpp"

void ConversionUtils::printValues() {
    if (std::isprint(ConversionUtils::getC())) {
        std::cout << "char: '" << ConversionUtils::getC() << "'" << std::endl;
    } else if (ConversionUtils::getIntNum() >= 0 &&
               ConversionUtils::getIntNum() <= 255) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    std::cout << "int: " << ConversionUtils::getIntNum() << std::endl;

    float floatNumValue = ConversionUtils::getFloatNum();
    // 条件に応じて出力形式を切り替える
    // loatNumValue が非常に大きい値（100万以上）であるか、
    // 非常に小さい値（0に近い値、0.000001未満）である」場合にTRUE
    if (std::abs(floatNumValue) >= 1e+6 ||
        (floatNumValue != 0.0 && std::abs(floatNumValue) < 1e-6)) {
        // 小数点以下5桁に設定
        std::cout << std::fixed << std::setprecision(5);
        // 指数表記で出力する設定
        std::cout << std::scientific;
    } else {
        // 小数点以下1桁に設定
        std::cout << std::fixed << std::setprecision(1);
    }
    std::cout << "float: " << floatNumValue << "f" << std::endl;

    double doubleNumValue = ConversionUtils::getDoubleNum();
    // doubleも同様に出力形式を切り替える
    if (std::abs(doubleNumValue) >= 1e+6 ||
        (doubleNumValue != 0.0 && std::abs(doubleNumValue) < 1e-6)) {
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
        return TYPE_STRING;
    }

    if (ConversionUtils::isSingleChar(input)) {
        return TYPE_CHAR;
    }

    long intValue;
    if (ConversionUtils::isInteger(input, intValue)) {
        return TYPE_INT;
    }

    bool endsWithF;
    // 正しい小数点数字かどうかをチェック
    // かつ、最後にfの文字があれば、endsWithFがTRUEになる
    if (ConversionUtils::isFloatingPoint(input, endsWithF)) {
        return endsWithF ? TYPE_FLOAT : TYPE_DOUBLE;
    }

    return TYPE_STRING;
}

void ConversionUtils::toChar(const std::string input, const std::string &type) {
    if (type == TYPE_CHAR) {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setC(input[0]);
            return;
        }
    } else if (type == TYPE_INT) {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
        // ASCII範囲内の値か確認
        if (value >= 0 && value <= 255) {
            ConversionUtils::setC(static_cast<char>(value));
            return;
        }
    } else if (type == TYPE_FLOAT || type == TYPE_DOUBLE) {
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
    if (type == TYPE_CHAR) {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setIntNum(static_cast<int>(input[0]));
        }
        return;
    } else if (type == TYPE_INT) {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
       if (value > static_cast<long>(std::numeric_limits<int>::max())) {
            std::cout << RED_START << "Error: intのオーバーフローを検出しました。INT_MAXを設定します。"
            << COLOR_END << std::endl;
            ConversionUtils::setIntNum(std::numeric_limits<int>::max());
        } else if (value < static_cast<long>(std::numeric_limits<int>::min())) {
            std::cout << RED_START << "Error: intのアンダーフローを検出しました。INT_MINを設定します。"
            << COLOR_END << std::endl;
           ConversionUtils::setIntNum(std::numeric_limits<int>::min());
        } else {
            ConversionUtils::setIntNum(static_cast<int>(value));
        }
        return;
    } else if (type == TYPE_FLOAT || type == TYPE_DOUBLE) {
        // 浮動小数点型の場合
        double value = std::strtod(input.c_str(), NULL);
        if (value > static_cast<double>(std::numeric_limits<int>::max())) {
            std::cout << RED_START << "Error: intのオーバーフローを検出しました。INT_MAXを設定します。"
            << COLOR_END << std::endl;
             ConversionUtils::setIntNum(std::numeric_limits<int>::max());
        } else if (value < static_cast<double>(std::numeric_limits<int>::min())) {
            std::cout << RED_START << "Error: intのアンダーフローを検出しました。INT_MINを設定します。"
            << COLOR_END << std::endl;
            ConversionUtils::setIntNum(std::numeric_limits<int>::min());
        } else {
            ConversionUtils::setIntNum(static_cast<int>(value));
        }
        return;
    }

    // 変換できない場合
    ConversionUtils::setIntNum(0);
}

void ConversionUtils::toFloat(const std::string input,
                              const std::string &type) {
    if (type == TYPE_CHAR) {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setFloatNum(static_cast<float>(input[0]));
            return;
        }
    } else if (type == TYPE_INT) {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
        if (static_cast<double>(value) > static_cast<double>(FLT_MAX)) {
            std::cout << RED_START << "Error: floatのオーバーフローを検出しました。FLT_MAXを設定します。"
            << COLOR_END << std::endl;
            ConversionUtils::setFloatNum(FLT_MAX);
        } else if (static_cast<double>(value) < static_cast<double>(-FLT_MAX)) {
            std::cout << RED_START << "Error: floatのアンダーフローを検出しました。-FLT_MAXを設定します。"
            << COLOR_END << std::endl;
            ConversionUtils::setFloatNum(-FLT_MAX);
        } else {
            ConversionUtils::setFloatNum(static_cast<float>(value));
        }
        return;
    } else if (type == TYPE_FLOAT || type == TYPE_DOUBLE) {
        // 浮動小数点型の場合
        char *endPtr;
        double value = std::strtod(input.c_str(), &endPtr);
        // 'f' (float) または終端文字
        if (*endPtr == 'f' || *endPtr == '\0') {
            if (value > static_cast<double>(FLT_MAX)) {
                std::cout << RED_START << "Error: floatのオーバーフローを検出しました。FLT_MAXを設定します。"
                << COLOR_END << std::endl;
                ConversionUtils::setFloatNum(FLT_MAX);
            } else if (value < static_cast<double>(-FLT_MAX)) {
                std::cout << RED_START << "Error: floatのアンダーフローを検出しました。-FLT_MAXを設定します。"
                << COLOR_END << std::endl;
                ConversionUtils::setFloatNum(-FLT_MAX);
            } else {
                ConversionUtils::setFloatNum(value);
            }
            return;
        }
    }

    // 変換できない場合
    ConversionUtils::setFloatNum(0.0f);
}

void ConversionUtils::toDouble(const std::string input,
                               const std::string &type) {
    if (type == TYPE_CHAR) {
        // 文字型の場合
        if (input.length() == 1) {
            ConversionUtils::setDoubleNum(static_cast<double>(input[0]));
        }
        return;
    } else if (type == TYPE_INT) {
        // 整数型の場合
        long value = std::strtol(input.c_str(), NULL, 10);
        if (static_cast<double>(value) > DBL_MAX) {
            std::cout << RED_START << "Error: doubleのオーバーフローを検出しました。DBL_MAXを設定します。"
            << COLOR_END << std::endl;
            ConversionUtils::setDoubleNum(DBL_MAX);
        } else if (static_cast<double>(value) < -DBL_MAX) {
            std::cout << RED_START << "Error: doubleのアンダーフローを検出しました。-DBL_MAXを設定します。"
            << COLOR_END << std::endl;
            ConversionUtils::setDoubleNum(-DBL_MAX);
        } else {
           ConversionUtils::setDoubleNum(static_cast<double>(value));
        }
        return;
    } else if (type == TYPE_FLOAT || type == TYPE_DOUBLE) {
        // 浮動小数点型の場合
        char *endPtr;
        double value = std::strtod(input.c_str(), &endPtr);
        // 'f' (float) または終端文字
        if (*endPtr == 'f' || *endPtr == '\0') {
            if (value > DBL_MAX) {
                std::cout << RED_START << "Error: doubleのオーバーフローを検出しました。DBL_MAXを設定します。"
                << COLOR_END << std::endl;
                ConversionUtils::setDoubleNum(DBL_MAX);
            } else if (value < -DBL_MAX) {
                std::cout << RED_START << "Error: doubleのアンダーフローを検出しました。-DBL_MAXを設定します。"
                << COLOR_END << std::endl;
                ConversionUtils::setDoubleNum(-DBL_MAX);
            } else {
                ConversionUtils::setDoubleNum(value);
            }
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

    // trimmedInputが浮動小数点数の構文に正しく含まれているか確認
    //  変換処理がどこで停止したかをこのポインタに格納します。
    char *endPtr;
    std::strtod(trimmedInput.c_str(), &endPtr);
    return *endPtr == '\0';
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

char ConversionUtils::c = '\0';
int ConversionUtils::intNum = 0;
double ConversionUtils::doubleNum = 0.0;
float ConversionUtils::floatNum = 0.0f;

const char *ConversionUtils::specialFloatValues[12][4] = {
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
