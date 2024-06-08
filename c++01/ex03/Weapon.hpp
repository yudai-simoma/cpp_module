/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:36:42 by yshimoma          #+#    #+#             */
/*   Updated: 2024/06/08 23:36:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>
#include <string>

class Weapon {
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType() const;
    void setType(std::string type);
private:
    std::string _type;
};

#endif
