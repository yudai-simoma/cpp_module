/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 18:56:06 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./include/Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        // ShrubberyCreationFormの作成
        ShrubberyCreationForm shrubbery("targe1t", "ShrubberyCreationForm", 145,
                                        137);

        // 署名されていない状態で実行
        std::cout << "\n--- 署名されていない状態で実行 ---" << std::endl;
        Bureaucrat b1("Bob", 1);
        try {
            b1.executeForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // サインできるグレードが低いBureaucratで署名
        std::cout << "\n--- サインできるグレードが低いBureaucratで署名 ---"
                  << std::endl;
        Bureaucrat b2("Alice", 150);
        try {
            b2.signForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // グレードが高いBureaucratで署名し、実行
        std::cout << "\n--- グレードが高いBureaucratで署名し、実行 ---"
                  << std::endl;
        Bureaucrat b3("Charlie", 100);
        b3.signForm(shrubbery);
        b3.executeForm(shrubbery);

        // 実行できるグレードが低いBureaucratで実行
        std::cout << "\n--- 実行できるグレードが低いBureaucratで実行 ---"
                  << std::endl;
        ShrubberyCreationForm shrubbery2("target2", "ShrubberyCreationForm2",
                                         145, 137);
        Bureaucrat b4("David", 140);
        try {
            b4.signForm(shrubbery2);
            b4.executeForm(shrubbery2);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // すでに署名済みのFormに署名しようとする
        std::cout << "\n--- すでに署名済みのFormに署名しようとする ---"
                  << std::endl;
        try {
            b3.signForm(shrubbery);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // RobotomyRequestFormの作成
        std::cout << "\n--- RobotomyRequestFormの作成 ---" << std::endl;
        RobotomyRequestForm robotomy("target3", "RobotomyRequestForm", 72, 45);

        // 署名されていない状態で実行
        std::cout << "\n--- 署名されていない状態で実行 ---" << std::endl;
        Bureaucrat b5("Eve", 1);
        try {
            b5.executeForm(robotomy);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // グレードが高いBureaucratで署名し、実行
        std::cout << "\n--- グレードが高いBureaucratで署名し、実行 ---"
                  << std::endl;
        Bureaucrat b6("Frank", 40);
        b6.signForm(robotomy);
        b6.executeForm(robotomy);
        b6.executeForm(robotomy);
        b6.executeForm(robotomy);
        b6.executeForm(robotomy);
        b6.executeForm(robotomy);

        // 実行できるグレードが低いBureaucratで実行
        std::cout << "\n--- 実行できるグレードが低いBureaucratで実行 ---"
                  << std::endl;
        Bureaucrat b7("Grace", 50);
        try {
            b7.signForm(robotomy);
            b7.executeForm(robotomy);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // PresidentialPardonFormの作成
        std::cout << "\n--- PresidentialPardonFormの作成 ---" << std::endl;
        PresidentialPardonForm pardon("target4", "PresidentialPardonForm", 25,
                                      5);

        // 署名されていない状態で実行
        std::cout << "\n--- 署名されていない状態で実行 ---" << std::endl;
        Bureaucrat b8("Ivy", 1);
        try {
            b8.executeForm(pardon);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // グレードが高いBureaucratで署名し、実行
        std::cout << "\n--- グレードが高いBureaucratで署名し、実行 ---"
                  << std::endl;
        Bureaucrat b9("Jack", 5);
        b9.signForm(pardon);
        b9.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << RED_START << e.what() << COLOR_END << std::endl;
    }

    return 0;
}
