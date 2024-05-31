/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:27 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/01 01:57:31 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook() : _max_id(0) {
    std::clog << "PhoneBook object created" << std::endl;
}

PhoneBook::~PhoneBook() {
    std::clog << "PhoneBook object destroyed" << std::endl;
}

/* 連絡先を追加する */
void PhoneBook::add() {
    std::string input;
    int id = this->_max_id % MAX_CONTACT_SIZE;

    this->_max_id++;
    this->_contacts[id].setId(this->_max_id);
    this->_getValidatedInput(input, "Please enter First Name\t\t: ");
    this->_contacts[id].setFirstName(input);
    this->_getValidatedInput(input, "Please enter LastName\t\t: ");
    this->_contacts[id].setLastName(input);
    this->_getValidatedInput(input, "Please enter Nickname\t\t: ");
    this->_contacts[id].setNickname(input);
    this->_getValidatedInput(input, "Please enter PhoneNumber\t: ");
    this->_contacts[id].setPhoneNumber(input);
    this->_getValidatedInput(input, "Please enter DarkestSecret\t: ");
    this->_contacts[id].setDarkestSecret(input);
}

/* 連絡先を表示し、検索させる */
void PhoneBook::search() {
    if (this->_max_id == 0) {
        std::cout << "There are no registered contacts." << std::endl;
        return;
    }
    std::cout << std::setw(10) << std::right << "ID"
              << "|";
    std::cout << std::setw(10) << std::right << "FirstName"
              << "|";
    std::cout << std::setw(10) << std::right << "LastName"
              << "|";
    std::cout << std::setw(10) << std::right << "Nickname"
              << "|" << std::endl;
    for (int i = 0; i < MAX_CONTACT_SIZE; i++) {
        this->_putContact(this->_contacts[i]);
    }
    int id = 0;
    while (true) {
        id = this->_numberEntry();
        if (id > 0 && id <= this->_max_id) {
            this->_putContactDetail(this->_contacts[id - 1]);
            break;
        } else {
            std::cout << "Please enter a valid value." << std::endl;
        }
    }
}

/* プログラムを終了する */
void PhoneBook::exit() {
    return;
}

void PhoneBook::_putContact(Contact& contact) {
    std::stringstream ss;
    std::string str;

    ss << contact.getId();
    ss >> str;
    std::cout << std::setw(10) << std::right << _truncateString(str) << "|";
    std::cout << std::setw(10) << std::right << _truncateString(contact.getFirstName()) << "|";
    std::cout << std::setw(10) << std::right << _truncateString(contact.getLastName()) << "|";
    std::cout << std::setw(10) << std::right << _truncateString(contact.getNickname()) << "|"
              << std::endl;
}

int PhoneBook::_numberEntry() {
    int id = 0;
    std::stringstream ss;
    std::string str;

    std::cout << "Please enter the number of the contact to display: ";
    std::getline(std::cin, str);
    if (std::cin.eof()) {
        std::cout << "EOF detected. Exiting the program." << std::endl;
        std::exit(EXIT_SUCCESS);
    }
    ss << str;
    ss >> id;
    return id;
}

void PhoneBook::_putContactDetail(Contact& contact) {
    std::cout << "ID\t\t: " << contact.getId() << std::endl;
    std::cout << "FirstName\t: " << contact.getFirstName() << std::endl;
    std::cout << "LastName\t: " << contact.getLastName() << std::endl;
    std::cout << "Nickname\t: " << contact.getNickname() << std::endl;
    std::cout << "PhoneNumber\t: " << contact.getPhoneNumber() << std::endl;
    std::cout << "DarkestSecret\t: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::_getValidatedInput(std::string& input, const std::string& msg) {
    while (true) {
        input = "";
        std::cout << msg;
        std::getline(std::cin, input);
        if (!input.empty() && input.size() != 0) {
            return;
        } else {
            std::cout << "Please enter at least one character." << std::endl;
        }
    }
}

std::string PhoneBook::_truncateString(const std::string& str) {
    size_t size = str.length();

    if (size < 10) {
        return str;
    } else {
        std::string ret = str.substr(0, 9);
        return ret + ".";
    }
}
