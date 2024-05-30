/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:27 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/31 04:04:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook(): _max_id(0) {
	std::clog << "PhoneBookオブジェクト生成" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::clog << "PhoneBookオブジェクト破壊" << std::endl;
}

void PhoneBook::add() {
	std::string input;
	int id = _max_id % MAX_CONTACT_SIZE;

	_max_id++;
	_contacts[id].setId(_max_id);
	getValidatedInput(input, "FirstNameを入力してください\t: ");
	_contacts[id].setFirstName(input);
	getValidatedInput(input, "LastNameを入力してください\t: ");
	_contacts[id].setLastName(input);
	getValidatedInput(input, "Nicknameを入力してください\t: ");
	_contacts[id].setNickname(input);
	getValidatedInput(input, "PhoneNumberを入力してください\t: ");
	_contacts[id].setPhoneNumber(input);
	getValidatedInput(input, "DarkestSecretを入力してください\t: ");
	_contacts[id].setDarkestSecret(input);
}

void PhoneBook::search() {
	if (_max_id == 0) {
		std::cout << "登録されている連絡先は0件です。" << std::endl;
		return ;
	}
	// TODO: カラム名を追加
	std::cout << std::setw(10) << std::right << "ID" << "|";
	std::cout << std::setw(10) << std::right << "FirstName" << "|";
	std::cout << std::setw(10) << std::right << "LastName" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	for(int i = 0; i < MAX_CONTACT_SIZE; i++) {
		putContact(_contacts[i]);
	}
	int id = 0;
	while (true) {
		id = numberEntry();
		if (id > 0 && id <= _max_id) {
			putContactDetail(_contacts[id - 1]);
			break;
		} else {
			std::cout << "正しい値を入力してください。" << std::endl;
		}
	}
}

void PhoneBook::exit() {
	return ;
}

/** 以下からprivate関数 */

/*
SEARCH：特定の連絡先を表示
	保存された連絡先（ID、名、性、ニックネーム）を4列のリストとして表示します。
	各列は10文字幅でなければなりません。パイプ文字（'|'）で区切られます。
	テキストは右寄せでなければなりません。
	テキストが10文字より長い場合は、テキストを切り詰め、表示可能な最後の文字をドット.にする
*/
void PhoneBook::putContact(Contact& contact) {
	//TODO: スペースが入った時に表示がおかしくなる。
	std::cout << std::setw(10) << std::right << contact.getId() << "|";
	std::cout << std::setw(10) << std::right << contact.getFirstName() << "|";
	std::cout << std::setw(10) << std::right << contact.getLastName() << "|";
	std::cout << std::setw(10) << std::right << contact.getNickname() << "|" << std::endl;
}

// TODO: 以下の関数を作る
//		・テキストが10文字より長い場合は、テキストを切り詰め、表示可能な最後の文字をドット.にする
// std::string f(std::string& str) {

// }

int PhoneBook::numberEntry() {
	int id = 0;
	std::stringstream ss;
	std::string str;

	std::cout << "表示する連絡先の番号を入力してください: ";
	std::getline(std::cin, str);
	if (std::cin.eof()) {
        // EOFが入力された場合の処理
        std::cout << "EOFが入力されたためプログラムを終了します。" << std::endl;
        std::exit(EXIT_SUCCESS);
    }
	ss << str;
	ss >> id;
	return id;
}

void PhoneBook::putContactDetail(Contact& contact) {
	std::cout << "ID\t\t: " << contact.getId() << std::endl;
	std::cout << "FirstName\t: " << contact.getFirstName() << std::endl;
	std::cout << "LastName\t: " << contact.getLastName() << std::endl;
	std::cout << "Nickname\t: " << contact.getNickname() << std::endl;
	std::cout << "PhoneNumber\t: " << contact.getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret\t: " << contact.getDarkestSecret() << std::endl;	
}

void PhoneBook::getValidatedInput(std::string& input, const std::string& msg) {
	while (true) {
		input = "";
		std::cout << msg;
		std::getline(std::cin, input);
		if (!input.empty() && input.size() != 0) {
			return;
		} else {
			std::cout << "1文字以上入力してください。" << std::endl;
		}
	}
}
