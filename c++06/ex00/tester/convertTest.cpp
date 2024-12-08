#include <iostream>
#include <iomanip>  // For std::setprecision
#include <cmath>    // For isnan, isinf
#include <vector>   // For error tracking
#include <string>
#include "../include/ScalarConverter.hpp"
#include "../include/ConversionUtils.hpp"

// テストケースの結果を格納する構造体
struct TestResult {
    std::string input;
    bool passed;
    std::string message;
};

std::vector<TestResult> testResults; // テスト結果を収集するリスト

void testScalarConverter(const char *input, char expectedC, int expectedInt,
                         double expectedDouble, float expectedFloat) {
    static int testNum = 1; // 静的変数でテスト番号を管理
    // 実行
    ScalarConverter::convert(input);

    // 結果を取得
    char actualC = ConversionUtils::getC();
    int actualInt = ConversionUtils::getIntNum();
    double actualDouble = ConversionUtils::getDoubleNum();
    float actualFloat = ConversionUtils::getFloatNum();

    // 検証
    bool passed = true;
    std::ostringstream message;
    message << "[" << testNum++ << "]Testing input: " << input << std::endl;

    if (actualC != expectedC) {
        passed = false;
        message << "  ❌ Char mismatch: Expected='" << expectedC
                << "', Actual='" << actualC << "'\n";
    }
    if (actualInt != expectedInt) {
        passed = false;
        message << "  ❌ Int mismatch: Expected=" << expectedInt
                << ", Actual=" << actualInt << "\n";
    }
    if (!std::isnan(expectedDouble) && !std::isinf(expectedDouble) &&
        actualDouble != expectedDouble) {
        passed = false;
        message << "  ❌ Double mismatch: Expected=" << expectedDouble
                << ", Actual=" << actualDouble << "\n";
    } else if ((std::isnan(expectedDouble) && !std::isnan(actualDouble)) ||
               (std::isinf(expectedDouble) && !std::isinf(actualDouble))) {
        passed = false;
        message << "  ❌ Double special value mismatch: Expected=" << expectedDouble
                << ", Actual=" << actualDouble << "\n";
    }
    if (!std::isnan(expectedFloat) && !std::isinf(expectedFloat) &&
        actualFloat != expectedFloat) {
        passed = false;
        message << "  ❌ Float mismatch: Expected=" << expectedFloat
                << ", Actual=" << actualFloat << "\n";
    } else if ((std::isnan(expectedFloat) && !std::isnan(actualFloat)) ||
               (std::isinf(expectedFloat) && !std::isinf(actualFloat))) {
        passed = false;
        message << "  ❌ Float special value mismatch: Expected=" << expectedFloat
                << ", Actual=" << actualFloat << "\n";
    }

    if (passed) {
        message << "  ✅ Test passed!";
    }

    std::cout << message.str() << std::endl;
    testResults.push_back({input, passed, message.str()});
}

/**
 * c++ -I./include -std=c++11 ./tester/convertTest.cpp \
   ./src/ConversionUtils.cpp ./src/ScalarConverter.cpp && ./a.out
 */
int main() {
    // テストケース
    testScalarConverter("7", '\a', 7, 7.0, 7.0f);
    testScalarConverter("8.0", '\b', 8, 8.0, 8.0f);
    testScalarConverter("9.0f", '\t', 9, 9.0, 9.0f);
    testScalarConverter("a", 'a', 97, 97.0, 97.0f);
    testScalarConverter("-128", '\0', -128, -128.0, -128.0f);
    testScalarConverter("300", '\0', 300, 300.0, 300.0f);
    testScalarConverter("nan", '\0', 0, NAN, NAN);
    testScalarConverter("inf", '\0', 0, INFINITY, INFINITY);
    testScalarConverter("-inf", '\0', 0, -INFINITY, -INFINITY);

    // 結果の要約
    int passedCount = 0;
    for (const auto &result : testResults) {
        if (result.passed) {
            passedCount++;
        } else {
            std::cerr << result.message << std::endl; // エラー詳細を表示
        }
    }

    std::cout << "Summary: " << passedCount << "/" << testResults.size()
              << " tests passed." << std::endl;

    return passedCount == testResults.size() ? 0 : 1;
}
