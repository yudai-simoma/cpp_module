/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:20:15 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 16:51:04 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
#define __PRESIDENTIAL_PARDON_FORM_HPP__

#include "./AForm.hpp"
#include "Config.hpp"

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const& target, std::string const& name,
                           int gradeRequiredToSign, int gradeRequiredToExecute);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const& executor) const;

   protected:
   private:
    static const int GRADE_REQUIRED_TO_SIGN = 25;
    static const int GRADE_REQUIRED_TO_EXECUTE = 5;
    std::string _target;
};

#endif
