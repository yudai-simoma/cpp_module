/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:07:51 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/22 01:23:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ClapTrap.hpp"

int main() {
    std::cout << "---------------------" << std::endl;
    // テスト 1: コンストラクタ, デストラクタ, attack
    {
        ClapTrap ct1("CT-1");
        ct1.attack("Target-A");

        std::cout << ct1 << std::endl;
    }
    std::cout << "---------------------" << std::endl;

    // テスト 2:  コピーコンストラクタ, 代入演算子
    {
        ClapTrap ct2("CT-2");
        ct2.setAttackDamage(3);
        ClapTrap ct3(ct2);
        ct3.attack("Target-B");

        ClapTrap ct4("CT-4");
        ct4 = ct3;
        ct4.attack("Target-C");

        std::cout << ct2 << std::endl;
        std::cout << ct3 << std::endl;
        std::cout << ct4 << std::endl;
    }
    std::cout << "---------------------" << std::endl;

    // テスト 3: takeDamage, beRepaired
    {
        ClapTrap ct5("CT-5");
        ct5.takeDamage(4);
        ct5.beRepaired(2);
        ct5.takeDamage(100);

        std::cout << ct5 << std::endl;
    }
    std::cout << "---------------------" << std::endl;

    return 0;
}
