/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:39:27 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/06 21:39:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie *zombie = newZombie("Zombie1");
    zombie->announce();

    randomChump("Zombie2");

    delete zombie;
    return 0;
}
