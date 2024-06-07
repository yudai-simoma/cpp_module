
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
public:
    HumanB();
    ~HumanB();
    void attack();
    void setWeapon(Weapon& weapon);
private:
    std::string _name;
    Weapon& _weapon;
};

#endif
