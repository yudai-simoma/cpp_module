/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:46:29 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/19 23:23:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command = commandEntry();
	if (string_upper(command) == "ADD") {
		phoneBook.add();
	} else if (string_upper(command) == "SEARCH") {
		phoneBook.search();
	} else if (string_upper(command) == "EXIT") {
		phoneBook.exit();
	} else {
		std::cout << "入力するコマンドはADD, SEARCH, EXITにしてください。" << std::endl;
	}
	return 0;
}

std::string commandEntry() {
	std::string str = "";

	std::cout << "実行したいコマンドを入力してください: ";
	std::cin >> str;
	return str;
}

std::string string_upper(std::string src) {
	std::string ret = src;
    std::locale l = std::locale::classic();
    for (int i = 0; i < (int)src.size(); i++) {
        ret[i] = std::toupper(src[i], l);
    }
	return ret;
}