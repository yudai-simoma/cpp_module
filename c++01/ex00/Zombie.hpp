/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:39:47 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/06 21:39:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie {
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
