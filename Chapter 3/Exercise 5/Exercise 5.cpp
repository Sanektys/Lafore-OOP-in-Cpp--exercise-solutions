#include <iostream>

int main() {
    for (int r = 1; r <= 20; r++) {
        for (int c = 20 * 2 - 1; c >= 1; c--)
            std::cout << ((r * 2 - 1 >= c) ? 'X' : ' ');
        std::cout << std::endl;
    }

    return 0;
}