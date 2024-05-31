/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:19:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/01 01:57:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
    : _id(0), _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {
    std::clog << "Contact object created" << std::endl;
}

Contact::~Contact() {
    std::clog << "Contact object destroyed" << std::endl;
}

void Contact::setId(int id) {
    this->_id = id;
}

int Contact::getId() {
    return this->_id;
}

void Contact::setFirstName(std::string firstName) {
    this->_firstName = firstName;
}

std::string Contact::getFirstName() {
    return this->_firstName;
}

void Contact::setLastName(std::string lastName) {
    this->_lastName = lastName;
}

std::string Contact::getLastName() {
    return this->_lastName;
}

void Contact::setNickname(std::string nickname) {
    this->_nickname = nickname;
}

std::string Contact::getNickname() {
    return this->_nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber() {
    return this->_phoneNumber;
}

void Contact::setDarkestSecret(std::string drakestSecret) {
    this->_darkestSecret = drakestSecret;
}

std::string Contact::getDarkestSecret() {
    return this->_darkestSecret;
}
