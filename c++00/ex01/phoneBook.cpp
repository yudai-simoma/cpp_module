/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:27 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/19 23:24:09 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook(): _id(0) {
	std::cout << "PhoneBookオブジェクト生成" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBookオブジェクト破壊" << std::endl;
}

void PhoneBook::add() {
	//TODO: リセットはいらない。
	std::string input;
	if (_id == MAX_CONTACT_SIZE) {
		_id == 1;
	} else {
		_id++;
	}
	getValidatedInput(input, "名を入力してください: ");
	_contacts[_id].setFirstName(input);
	getValidatedInput(input, "性を入力してください: ");
	_contacts[_id].setLastName(input);
	getValidatedInput(input, "ニックネームを入力してください: ");
	_contacts[_id].setNickname(input);
	getValidatedInput(input, "電話番号を入力してください: ");
	_contacts[_id].setPhoneNumber(input);
	getValidatedInput(input, "暗黙の秘密を入力してください: ");
	_contacts[_id].setDarkestSecret(input);
}

void PhoneBook::search() {
	for(int i = 0; i < _id; i++) {
		putContact(i + 1, _contacts[i]);
	}
	int id = 0;
	id = numberEntry();
	if (id > 0 && id <= _id) {
		putContactDetail(_contacts[id]);
	} else {
		std::cout << "入力する番号は1 ~ " << _id << "にしてください。" << std::endl;
	}
}

void PhoneBook::exit() {
	exit();
}

/** 以下からprivate関数 */

void PhoneBook::putContact(int id, Contact contact) {
	//TODO: フォーマット要件に合わせる。
	std::cout << id << "|" << contact.getFirstName() << "|" << contact.getLastName() << "|" << contact.getNickname() << "|" << std::endl;
}

int PhoneBook::numberEntry() {
	int id = 0;

	std::cout << "表示する連絡先の番号を入力してください: ";
	std::cin >> id;
	return id;
}

void PhoneBook::putContactDetail(Contact contact) {
	std::cout << "FirstName: " << contact.getFirstName() << std::endl;
	std::cout << "LastName: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "PhoneNumber: " << contact.getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret: " << contact.getDarkestSecret() << std::endl;	
}

void PhoneBook::getValidatedInput(std::string& input, const std::string msg) {
	while (true) {
		input = "";
		std::cout << msg;
		std::cin >> input;
		if (!input.empty() && input.size() != 0) {
			return;
		} else {
			std::cout << "1文字以上入力してください。" << std::endl;
		}
	}
}
