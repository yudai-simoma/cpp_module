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
    try {
        Zombie* zombie = newZombie("Zombie1");
        zombie->announce();

        randomChump("Zombie2");

        delete zombie;
        return 0;
    } catch (const std::bad_alloc& e) {
        return 1;
    }
}
