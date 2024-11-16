/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:00:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/16 19:55:55 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    // 正常なBureaucratの作成
    try {
        Bureaucrat b1("Bob", 50);
        std::cout << "初期グレード " << b1 << std::endl;

        // Gradeの変更 (正常ケース)
        b1.incrementGrade();
        std::cout << "インクリメント " << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "デクリメント " << b1 << std::endl;

        // Gradeの限界値テスト
        Bureaucrat b2("Alice", 1);
        std::cout << "初期グレード " << b2 << std::endl;
        try {
            std::cout << "インクリメント例外処理" << std::endl;
            b2.incrementGrade();  // 例外が発生するはず
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        Bureaucrat b3("Charlie", 150);
        std::cout << b3 << std::endl;
        try {
            std::cout << "デクリメント例外処理" << std::endl;
            b3.decrementGrade();  // 例外が発生するはず
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // 不正なGradeでのBureaucratの作成
        try {
            std::cout << "不正な例外処理1" << std::endl;
            Bureaucrat b4("David", 0);  // 例外が発生するはず
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        try {
            std::cout << "不正な例外処理2" << std::endl;
            Bureaucrat b5("Eve", 151);  // 例外が発生するはず
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Unexpected Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
