/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:58:08 by yshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 20:26:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./include/Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    AForm* ppf;
    AForm* scf;
    Bureaucrat b("Bob", 1);

    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender1");
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender2");
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender3");

        std::cout << *rrf << std::endl;
        std::cout << *ppf << std::endl;
        std::cout << *scf << std::endl;

        b.signForm(*rrf);
        b.executeForm(*rrf);
        b.signForm(*ppf);
        b.executeForm(*ppf);
        b.signForm(*scf);
        b.executeForm(*scf);

        delete rrf;
        delete ppf;
        delete scf;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 存在しないフォーム名
    std::cout << "\n--- Invalid form name test ---" << std::endl;
    try {
        AForm* invalidForm =
            someRandomIntern.makeForm("invalid form", "target");
        (void)
            invalidForm;  // 未使用変数の警告を抑制、NULLが返ってくるので使用しない
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what()
                  << std::endl;  // ここには来ない
    }

    return 0;
}
