/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:56:38 by yshimoma          #+#    #+#             */
/*   Updated: 2024/12/16 21:27:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

int main() {
    // 1. デフォルトコンストラクタのテスト
    std::cout << "--- デフォルトコンストラクタのテスト ---" << std::endl;
    Array<int> emptyArray;
    std::cout << "空の配列のサイズ: " << emptyArray.size() << std::endl;

    // 2. パラメータ付きコンストラクタのテスト
    std::cout << "\n--- パラメータ付きコンストラクタのテスト ---" << std::endl;
    Array<int> intArray(5);
    std::cout << "intArrayのサイズ: " << intArray.size() << std::endl;
    for (size_t i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // 3. コピーコンストラクタのテスト
    std::cout << "\n--- コピーコンストラクタのテスト ---" << std::endl;
    Array<int> intArray2(3);
    for (size_t i = 0; i < intArray2.size(); ++i) {
        intArray2[i] = i * 10;
    }
    Array<int> copyArray(intArray2);

    std::cout << "copyArrayのサイズ: " << copyArray.size() << std::endl;
    for (size_t i = 0; i < copyArray.size(); ++i) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    // 元の配列を変更してもコピーには影響がないことを確認
    intArray2[0] = 999;
    std::cout << "intArray2を変更後copyArrayの値:";
    for (size_t i = 0; i < copyArray.size(); ++i) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    // 4. 代入演算子のテスト
    std::cout << "\n--- 代入演算子のテスト ---" << std::endl;
    Array<int> assignArray(2);
    for (size_t i = 0; i < assignArray.size(); ++i) {
        assignArray[i] = i * 100;
    }
    assignArray = intArray2;
    std::cout << "assignArrayのサイズ: " << assignArray.size() << std::endl;
    for (size_t i = 0; i < assignArray.size(); ++i) {
        std::cout << assignArray[i] << " ";
    }
    std::cout << std::endl;

    // 元の配列を変更してもコピーには影響がないことを確認
    intArray2[0] = 111;
    std::cout << "intArray2を変更後assignArrayの値:";
    for (size_t i = 0; i < assignArray.size(); ++i) {
        std::cout << assignArray[i] << " ";
    }
    std::cout << std::endl;

    // 5. [] 演算子のテストと範囲外アクセス時の例外テスト
    std::cout << "\n--- [] 演算子のテスト ---" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "こんにちは";
    strArray[1] = "世界";
    strArray[2] = "！";
    for (size_t i = 0; i < strArray.size(); ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    // 6. [] 範囲外アクセス時の例外テスト
    std::cout << "\n--- [] 演算子の例外テスト ---" << std::endl;
    try {
        strArray[5] = "エラー";  // 範囲外アクセス
    } catch (const std::exception& e) {
        std::cerr << "例外が発生しました: " << e.what() << std::endl;
    }
    return 0;
}
