#include <iostream>

int main() {
    std::cout << "Enter the initial contribution: ";
    float contribution;
    std::cin >> contribution;
    std::cout << "Enter duration in years: ";
    short years;
    std::cin >> years;
    std::cout << "Enter the interest rate: ";
    float rate;
    std::cin >> rate;
    
    for (int i = 0; i < years; i++)
        contribution += contribution * rate / 100;

    std::cout << "After " << years << " years you will got " << contribution << " dollar.\n";

    return 0;
}