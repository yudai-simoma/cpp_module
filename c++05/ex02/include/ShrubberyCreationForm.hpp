/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:15:39 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 16:51:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM_HPP__
#define __SHRUBBERY_CREATION_FORM_HPP__

#include <fstream>

#include "./AForm.hpp"
#include "Config.hpp"

class ShrubberyCreationForm : public AForm {
   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const& target, std::string const& name,
                          int gradeRequiredToSign, int gradeRequiredToExecute);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;

   protected:
   private:
    static const int GRADE_REQUIRED_TO_SIGN = 145;
    static const int GRADE_REQUIRED_TO_EXECUTE = 137;
    std::string _target;
};

#endif
