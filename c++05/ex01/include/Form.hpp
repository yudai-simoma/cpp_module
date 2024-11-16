/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:43 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/16 22:26:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

#define RED_START "\033[1;31m"
#define COLOR_END "\033[0m"

class Bureaucrat;

class Form {
   public:
    Form();
    Form(std::string const& name, int gradeRequiredToSign,
         int gradeRequiredToExecute);
    Form(Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string const& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
    void beSigned(Bureaucrat& bureaucrat);

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

   protected:
   private:
    std::string _name;
    bool _isSigned;
    int _gradeRequiredToSign;
    int _gradeRequiredToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
