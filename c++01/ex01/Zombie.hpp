
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

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

Zombie* zombieHorde(int N, std::string name);

#endif