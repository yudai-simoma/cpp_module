/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:04:57 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/22 19:53:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    // デフォルトコンストラクタ、コピーコンストラクタ、代入演算子のテスト
    ScavTrap scav1("Scavvy");
    ScavTrap scav2(scav1);
    ScavTrap scav3;
    scav3 = scav2;

    // attack(), takeDamage(), beRepaired() のテスト
    scav1.attack("Target1");
    scav2.takeDamage(30);
    scav3.beRepaired(20);

    // guardGate() のテスト
    scav1.guardGate();

    // 状態の確認
    std::cout << "Scav1: " << scav1 << std::endl;
    std::cout << "Scav2: " << scav2 << std::endl;
    std::cout << "Scav3: " << scav3 << std::endl;

    ScavTrap scav4("Scavvy2");
    ClapTrap& clapPtr = scav1;
    clapPtr.attack("Target1");

    return 0;
}
