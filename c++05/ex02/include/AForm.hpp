/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:43 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 15:15:12 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_FORM_HPP__
#define __A_FORM_HPP__

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Config.hpp"

class Bureaucrat;

class AForm {
   public:
    AForm();
    AForm(std::string const& name, int gradeRequiredToSign,
         int gradeRequiredToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    virtual void execute(Bureaucrat const & executor) const = 0;

    std::string const& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
    void beSigned(Bureaucrat& bureaucrat);
    void isExecutable(Bureaucrat const & bureaucrat) const;

    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };

    class AlreadySignedException : public std::exception {
       public:
        const char* what() const throw();
    };

    class NotSignedException : public std::exception {
        public:
         const char* what() const throw();
    };

   protected:
   private:
    std::string _name;
    bool _isSigned;
    int _gradeRequiredToSign;
    int _gradeRequiredToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
