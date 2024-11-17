/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:10:58 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 23:49:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Config.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
   public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string const& formName, std::string const& target);

   protected:
   private:
    static const int NUM_FORMS = 3;
    enum FormType {
        RobotomyRequest = 0,
        PresidentialPardon = 1,
        ShrubberyCreation = 2
    };
};

#endif
