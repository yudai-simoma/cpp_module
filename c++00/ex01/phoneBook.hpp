/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:29:33 by yshimoma          #+#    #+#             */
/*   Updated: 2024/05/31 17:41:44 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONE_BOOK__
#define __PHONE_BOOK__

#include "contact.hpp"
#include <sstream>
#include <iomanip>

#define MAX_CONTACT_SIZE 8

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void exit();
	private:
		void putContact(Contact& contact);
		int numberEntry();
		void putContactDetail(Contact& contact);
		void getValidatedInput(std::string& input, const std::string& msg);
		std::string truncateString(const std::string& str);
		
		int _max_id;
		Contact _contacts[MAX_CONTACT_SIZE];
};

#endif
