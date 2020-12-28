#include <iostream>

int main() {
    std::cout << "Enter the first fraction: ";
    short numeratorA;
    short denominatorA;
    char slash;
    std::cin >> numeratorA >> slash >> denominatorA;
    std::cout << "Enter the second fraction: ";
    short numeratorB;
    short denominatorB;
    std::cin >> numeratorB >> slash >> denominatorB;
    
    short resultNumerator = numeratorA * denominatorB + numeratorB * denominatorA;
    short resultDenominator = denominatorA * denominatorB;
    std::cout << "The amount is " << resultNumerator << '/' << resultDenominator;

    return 0;
}