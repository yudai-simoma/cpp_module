
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>
#include <string>

class Weapon {
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    std::string& getType();
    void setType(std::string type);
private:
    std::string _type;
};

#endif
