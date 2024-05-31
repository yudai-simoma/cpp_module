/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:46:29 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/31 23:28:28 by yshimoma         ###   ########.fr       */
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
            std::cout << "Invalid input." << std::endl << std::endl;
        }
    }
    return 0;
}

std::string commandEntry() {
    std::string str = "";

    std::cout << "-----" << std::endl;
    std::cout << "ADD, SEARCH, EXIT" << std::endl;
    std::cout << "Please enter the command you want to execute: ";
    if (std::getline(std::cin, str)) {
        return str;
    } else if (std::cin.eof()) {
        std::cout << "EOF detected. Exiting the program." << std::endl;
        std::exit(EXIT_SUCCESS);
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please choose from ADD, SEARCH, EXIT." << std::endl;
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
