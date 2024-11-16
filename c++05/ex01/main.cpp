/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/16 22:04:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    // 正常な Form の作成
    std::cout << "------ Form Creation Test ------" << std::endl;
    try {
        Form f1("Form A", 50, 100);
        std::cout << f1 << std::endl;

        // 不正なグレードでの Form の作成 (例外テスト)
        try {
            Form f2("Form B", 0, 100);  // GradeTooHighException
        } catch (const Form::GradeTooHighException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Form f3("Form C", 151, 100);
            std::cout << f3 << std::endl;  // GradeTooLowException
        } catch (const Form::GradeTooLowException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Form f4("Form C", 100, 0);  // GradeTooHighException
        } catch (const Form::GradeTooHighException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            Form f5("Form C", 100, 151);  // GradeTooLowException
            std::cout << f5 << std::endl;
        } catch (const Form::GradeTooLowException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Unexpected Exception caught: " << e.what() << std::endl;
    }

    // 署名テスト
    std::cout << "\n------ Sign Form Test ------" << std::endl;
    try {
        Bureaucrat b1("Bob", 25);
        Form f4("Form D", 50, 100);
        std::cout << "Form initial status: " << f4 << std::endl;
        b1.signForm(f4);  // 署名できる
        std::cout << "Form after signing: " << f4 << std::endl;

        Bureaucrat b2("Alice", 75);
        Form f5("Form E", 50, 100);
        b2.signForm(f5);  // 署名できない (GradeTooLowException)

        Bureaucrat b3("Charlie", 25);
        Form f6("Form F", 50, 100);
        b3.signForm(f6);
        b3.signForm(f6);  // すでに署名済み (AlreadySignedException)

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
