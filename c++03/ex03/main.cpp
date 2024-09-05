/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 02:12:54 by yshimoma          #+#    #+#             */
/*   Updated: 2024/09/05 17:00:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    // 1. DiamondTrapのインスタンス化と基本動作確認
    DiamondTrap diamond1("Sparkly");
    diamond1.attack("Target Monster");
    diamond1.setAttackDamage(50);
    diamond1.attack("Target Monster2");
    diamond1.takeDamage(20);
    diamond1.beRepaired(30);
    diamond1.whoAmI();
    std::cout << diamond1 << std::endl;

    // 2. コピーコンストラクタの確認
    DiamondTrap diamond2(diamond1);
    diamond2.whoAmI();

    // 3. 代入演算子の確認
    DiamondTrap diamond3("Rusty");
    diamond3 = diamond1;
    diamond3.whoAmI();

    // 4. ScavTrap, FragTrapのメソッド呼び出し確認
    diamond1.guardGate();
    diamond1.highFivesGuys();

    return 0;
}
