/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:36:07 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/08 23:36:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);

        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        Weapon aaa = Weapon("aaa");
        HumanB jim("Jim");

        jim.attack();

        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        jim.setWeapon(aaa);
        jim.attack();
    }

    return 0;
}
