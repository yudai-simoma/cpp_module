
#include "Zombie.hpp"

int main() {
    try {
        int N = 5;
        Zombie* zombies = zombieHorde(N, "Zombie");
        if (zombies == NULL) {
            return (1);
        }

        for (int i = 0; i < N; i++) {
            zombies[i].announce();
        }

        delete[] zombies;
        return 0;
    } catch (const std::bad_alloc& e) {
        return 1;
    }
}
