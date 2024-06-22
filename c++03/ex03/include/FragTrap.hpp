/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:20:32 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/22 23:23:32 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAG_TRAP_HPP__
#define __FRAG_TRAP_HPP__

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
   public:
    FragTrap();
    FragTrap(const std::string name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys();

   private:
};

std::ostream& operator<<(std::ostream& os, const FragTrap& fragTrap);

#endif
