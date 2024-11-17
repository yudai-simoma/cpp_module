/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:35 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 14:44:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <exception>
#include <iostream>
#include <string>

#include "./AForm.hpp"

#define RED_START "\033[1;31m"
#define COLOR_END "\033[0m"

class AForm;

class Bureaucrat {
   public:
    Bureaucrat();
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string const& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form);
    void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };

   protected:
   private:
    std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
