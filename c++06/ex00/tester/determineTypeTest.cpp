/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determineTypeTest.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:36:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/20 10:51:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>

#include <climits>  // Add this line
#include <cmath>    // for isinf and isnan
#include <iostream>
#include <limits>  // 境界値のために追加
#include <string>
#include <utility>
#include <vector>

#include "../include/ConversionUtils.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

// テストケースを保持する構造
struct TestCase {
    std::string input;
    std::string expectedOutput;
};

// テスト結果を表示するヘルパー関数
void runTests(const std::vector<TestCase>& testCases) {
    int passedTests = 0;
    int totalTests = testCases.size();

    std::cout << "=== ConversionUtils::determineType テスト結果 ===\n";

    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& test = testCases[i];
        std::string actualOutput = ConversionUtils::determineType(test.input);

        // テスト結果の判定
        if (actualOutput == test.expectedOutput) {
            ++passedTests;
            std::cout << GREEN << "[PASSED]" << RESET "Test " << i + 1
                      << ": Input = \"" << test.input << "\" -> Output = \""
                      << actualOutput << "\"\n";
        } else {
            std::cout << RED << "[FAILED]" << RESET "Test " << i + 1
                      << ": Input = \"" << test.input << "\" -> Expected = \""
                      << test.expectedOutput << "\", Got = \"" << actualOutput
                      << "\"\n";
        }
    }

    std::cout << "\n=== テスト結果: " << passedTests << "/" << totalTests
              << " Tests Passed ===\n";
}

/**
 * c++ -I./include -std=c++11 ./tester/determineTypeTest.cpp \
   ./src/ConversionUtils.cpp ./src/ScalarConverter.cpp && ./a.out
 */
int main() {
    // テストケースを定義
    std::vector<TestCase> testCases = {
        // 文字
        {"a", "char"},
        {"Z", "char"},
        {"1", "int"},
        {"!", "char"},

        // 整数
        {"42", "int"},
        {"-123", "int"},
        {"+123", "int"},
        {std::to_string(INT_MAX), "int"},
        {std::to_string(INT_MIN), "int"},
        {std::to_string(UINT_MAX), "overflow"},
        {"2147483648", "overflow"},
        {"-2147483649", "overflow"},

        // 浮動小数点数
        {"3.14f", "float"},
        {"-0.5", "double"},
        {"1.0f", "float"},
        {"3.40282e38f", "float"},
        {"3.40282e39", "double"},
        {"-1.7e308", "double"},
        {"1.7e308", "double"},
        {std::to_string(FLT_MAX), "double"},
        {std::to_string(FLT_MIN), "double"},
        {std::to_string(DBL_MAX), "double"},
        {std::to_string(DBL_MIN), "double"},

        // 特殊な数値表現
        // {"inf", "double"}, {"+inf", "double"}, {"-inf", "double"},
        // {"infinity", "double"}, {"+infinity", "double"}, {"-infinity",
        // "double"},
        // {"nan", "double"}, {"+nan", "double"}, {"-nan", "double"},
        // {"inff", "float"}, {"+inff", "float"}, {"-inff", "float"}, {"nanf",
        // "float"},
        // {"INF", "double"}, {"+INF", "double"}, {"-INF", "double"}, {"NAN",
        // "double"},
        // {"INFINITY", "double"}, {"-INFINITY", "double"}, {"NAN", "double"},
        // {"+INFINITY", "double"}, {"-INFINITY", "double"}, {"+NAN", "double"},
        // {"-NAN", "double"},

        // 誤った形式
        {"abc", "string"},
        {"", "string"},
        {"123abc", "string"},
        {"..", "string"},
        {".5.5", "string"},
        {"1..2", "string"},
        {"-+123", "string"},
        {"--123", "string"},
        {"1.0ff", "string"},

        // 指数表記のバリエーション
        {"1e2", "double"},
        {"1.0e2", "double"},
        {"1.0e+2", "double"},
        {"1.0e-2", "double"},
        {".1e2", "double"},
        {"-.1e2", "double"},
        {"1e+1000", "double"},

        // 空白を含む入力
        {" 42", "string"},
        {"42 ", "string"},
        {" 42 ", "string"},
        {"\n42", "string"},
        {"42\n", "string"},
        {"\t42", "string"},

        // 正規表現的な誤り
        {"++42", "string"},
        {"--42", "string"},
        {"42++", "string"},
        {"42--", "string"},
        {"42..", "string"},
        {"e42", "string"},
        {".e2", "string"},
        {"1e", "string"},

        // 非常に長い入力
        {std::string(1000, '1'), "overflow"},  // 1000桁の "1"

        // 数値形式に似た文字列
        {"0xFF", "string"},
        {"075.F.", "string"},
        {"", "string"},

        // エラーケース
        {"5f3", "string"},
        {"1.2f3", "string"},
        {"0..0", "string"}};

    // テストを実行
    runTests(testCases);

    return 0;
}
