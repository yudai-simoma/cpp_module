
#include "Zombie.hpp"

int main() {
    try {
        int N = 5;
        Zombie *zombie = zombieHorde(N, "Zombie");
        if (zombie == NULL) {
            return (1);
        }

        for (int i = 0; i < N; i++) {
            zombie[i].announce();
        }

        delete[] zombie;
        return 0;
    } catch(const std::bad_alloc& e) {
        return 1;
    }
}
