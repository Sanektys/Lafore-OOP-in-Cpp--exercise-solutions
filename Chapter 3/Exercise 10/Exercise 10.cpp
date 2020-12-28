#include <iostream>

int main() {
    std::cout << "Enter the initial contribution: ";
    float contribution;
    std::cin >> contribution;
    std::cout << "Enter the interest rate: ";
    float rate;
    std::cin >> rate;
    std::cout << "Enter the target amount on the account: ";
    float target;
    std::cin >> target;

    short years = 0;
    do {
        contribution += contribution * rate / 100;
        years++;
    } while (contribution < target);

    std::cout << "After " << years << " years you will got " << contribution << " dollar.\n";

    return 0;
}