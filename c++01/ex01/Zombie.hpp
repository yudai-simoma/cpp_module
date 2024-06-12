/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:44:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/13 00:44:42 by yshimoma         ###   ########.fr       */
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
    void setName(std::string name);

   private:
    std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
