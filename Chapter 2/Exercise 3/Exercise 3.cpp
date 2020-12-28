#include <iostream>

int main() {
    int number = 10;

    std::cout << number << std::endl;
    number += 10;
    std::cout << number << std::endl;
    std::cout << --number << std::endl;

    return 0;
}