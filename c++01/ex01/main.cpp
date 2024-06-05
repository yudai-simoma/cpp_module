
#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie *zombie = zombieHorde(N, "Zombie");

    for (int i = 0; i < N; i++) {
        zombie[i].announce();
    }

    for (int i = 0; i < N; i++) {
        delette zombie[i];
    }
    return 0;
}