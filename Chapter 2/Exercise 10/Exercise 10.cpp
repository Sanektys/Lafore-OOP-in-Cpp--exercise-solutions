#include <iostream>

int main() {
    std::cout << "Enter number of feets: ";
    short feet;
    std::cin >> feet;
    std::cout << "Enter number of shillings: ";
    short shilling;
    std::cin >> shilling;
    std::cout << "Enter number of pennies: ";
    float pennie;
    std::cin >> pennie;

    float multiplier = 100.0f / (12.0f * 20.0f);
    pennie += shilling * 12;
    pennie *= multiplier;

    std::cout << "Decimal feet: " << feet << '.' << static_cast<int>(pennie + 0.5f) << std::endl;

    return 0;
}