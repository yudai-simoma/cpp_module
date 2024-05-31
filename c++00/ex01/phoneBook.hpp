/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:29:33 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/01 00:06:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONE_BOOK__
#define __PHONE_BOOK__

#include "contact.hpp"
#include <sstream>
#include <iomanip>
#include <cstdlib>

#define MAX_CONTACT_SIZE 8

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void exit();
	private:
		void _putContact(Contact& contact);
		int _numberEntry();
		void _putContactDetail(Contact& contact);
		void _getValidatedInput(std::string& input, const std::string& msg);
		std::string _truncateString(const std::string& str);
		
		int _max_id;
		Contact _contacts[MAX_CONTACT_SIZE];
};

#endif
