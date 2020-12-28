#include <iostream>

int main() {
    unsigned int number;
    do {
        unsigned long fact = 1l;
        std::cout << "Enter integer number, or \"0\" for exit: ";
        std::cin >> number;
        if (number == 0)
            continue;

        for (int i = number; i > 0; i--)
            fact *= i;
        std::cout << "Factorial of number: " << fact << std::endl;
    } while (number != 0);

    return 0;
}