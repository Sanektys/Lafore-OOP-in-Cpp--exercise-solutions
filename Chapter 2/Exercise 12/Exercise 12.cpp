#include <iostream>

int main() {
    std::cout << "Enter number of decimal feets: ";
    short feet;
    char period;
    float pennie;
    std::cin >> feet >> period >> pennie;

    float multiplier = static_cast<float>(240) / 100;
    pennie *= multiplier;
    pennie /= 12;

    std::cout << "Equivalent amount in the legacy entry form: " << feet << '.' << pennie << std::endl;

    return 0;
}