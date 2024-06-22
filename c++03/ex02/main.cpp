/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:04:57 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/22 20:56:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    // デフォルトコンストラクタ、コピーコンストラクタ、代入演算子のテスト
    FragTrap frag1("Fragga");
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag2;

    // attack(), takeDamage(), beRepaired() のテスト
    frag1.attack("Target1");
    frag2.takeDamage(30);
    frag3.beRepaired(20);

    // highFivesGuys() のテスト
    frag1.highFivesGuys();

    // 状態の確認
    std::cout << "Frag1: " << frag1 << std::endl;
    std::cout << "Frag2: " << frag2 << std::endl;
    std::cout << "Frag3: " << frag3 << std::endl;

    return 0;
}
