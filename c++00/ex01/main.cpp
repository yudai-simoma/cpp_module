/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:46:29 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/31 18:14:25 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

// 関数のプロトタイプ宣言
std::string commandEntry();
std::string string_upper(std::string src);

int main() {
    PhoneBook phoneBook;
    std::string command;
    while (true) {
        command = commandEntry();
        if (string_upper(command) == "ADD") {
            phoneBook.add();
        } else if (string_upper(command) == "SEARCH") {
            phoneBook.search();
        } else if (string_upper(command) == "EXIT") {
            phoneBook.exit();
            break;
        } else {
            std::cout << "入力が不正です。" << std::endl << std::endl;
        }
    }
    return 0;
}

std::string commandEntry() {
    std::string str = "";

    std::cout << "-----" << std::endl;
    std::cout << "ADD, SEARCH, EXIT" << std::endl;
    std::cout << "上記から実行したいコマンドを入力してください: ";
    if (std::getline(std::cin, str)) {
        return str;
    } else if (std::cin.eof()) {
        std::cout << "EOFが入力されたためプログラムを終了します。" << std::endl;
        std::exit(EXIT_SUCCESS);
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "入力が不正です。ADD, SEARCH, EXITから選んでください。" << std::endl;
        return "";
    }
}

std::string string_upper(std::string src) {
    std::string ret = src;
    std::locale l = std::locale::classic();
    for (int i = 0; i < (int)src.size(); i++) {
        ret[i] = std::toupper(src[i], l);
    }
    return ret;
}
