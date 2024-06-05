
#include "Zombie.hpp"

Zombie::Zombie(): _name("") {
    std::cout << "Zombie object created" << std::endl;
}

Zombie::Zombie(std::string name): _name(name) {
    std::cout << _name << " is created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << this->_name << "コピペする" << std::endl;
}