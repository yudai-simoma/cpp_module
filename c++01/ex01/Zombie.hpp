
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie {
    public:
        Zombie();
        Zombie(std::string name);
        Zombie& operator=(const Zombie& other);
        ~Zombie();
        void announce(void);
    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
