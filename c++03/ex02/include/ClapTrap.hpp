/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:06:50 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/26 21:33:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_HPP__
#define __CLAP_TRAP_HPP__

#include <iostream>
#include <string>
#include <climits>

// 赤色の開始
#define RED_START "\033[1;31m"
// 色のリセット
#define COLOR_END "\033[0m"

class ClapTrap {
   public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    const std::string& getName() const;
    void setName(const std::string& name);
    int getHitPoints() const;
    void setHitPoints(const int hitPoints);
    int getEnergyPoints() const;
    void setEnergyPoints(const int energyPoints);
    int getAttackDamage() const;
    void setAttackDamage(const int attackDamage);

   private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap);

#endif
