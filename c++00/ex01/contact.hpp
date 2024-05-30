/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:50:52 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/20 21:36:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP_
#define __CONTACT_HPP_

#include <iostream>
#include <string>

class Contact {
	public:
		Contact();
		~Contact();
		void setId(int id);
		int getId();
		void setFirstName(std::string firstName);
		std::string getFirstName();
		void setLastName(std::string lastName);
		std::string getLastName();
		void setNickname(std::string nickname);
		std::string getNickname();
		void setPhoneNumber(std::string phoneNumber);
		std::string getPhoneNumber();
		void setDarkestSecret(std::string drakestSecret);
		std::string getDarkestSecret();
	private:
		int _id;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
