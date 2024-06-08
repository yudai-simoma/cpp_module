/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:35:56 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/08 23:35:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack();
private:
    std::string _name;
    Weapon& _weapon;
};

#endif
