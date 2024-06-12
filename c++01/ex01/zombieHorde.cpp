/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:44:11 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/13 00:44:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return NULL;
    }

    Zombie* zombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombies[i].setName(name);
    }
    return zombies;
}
