/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:53:40 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/23 02:13:53 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ___DIAMOND_TRAP_HPP__
#define ___DIAMOND_TRAP_HPP__

#include <iostream>
#include <string>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
   public:
    DiamondTrap();
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();

   private:
    std::string _name;
};

std::ostream& operator<<(std::ostream& os, const DiamondTrap& scavTrap);

#endif
