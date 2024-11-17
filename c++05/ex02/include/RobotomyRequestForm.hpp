/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:58:49 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 18:55:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
#define __ROBOTOMY_REQUEST_FORM_HPP__

// rand() と srand() を使うため
#include <cstdlib>
// time() を使うため
#include <ctime>

#include "./AForm.hpp"
#include "Config.hpp"

class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const& target, std::string const& name, int gradeRequiredToSign,
         int gradeRequiredToExecute);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;

   protected:
   private:
    static void initialize();
    
    static const int GRADE_REQUIRED_TO_SIGN = 72;
    static const int GRADE_REQUIRED_TO_EXECUTE = 45;
    std::string _target;
};

#endif
