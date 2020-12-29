#include <iostream>

struct Fraction
{
    int numeration;
    int denominator;
};

int main() {
    std::cout << "Enter the first fraction: ";
    char slash;
    Fraction fraction1;
    std::cin >> fraction1.numeration >> slash >> fraction1.denominator;

    std::cout << "Enter the second fraction: ";
    Fraction fraction2;
    std::cin >> fraction2.numeration >> slash >> fraction2.denominator;

    Fraction fraction3;
    fraction3.numeration = fraction1.numeration * fraction2.denominator
                         + fraction2.numeration * fraction1.denominator;
    fraction3.denominator = fraction1.denominator * fraction2.denominator;
    std::cout << "The amount is " << fraction3.numeration << '/' << fraction3.denominator;

    return 0;
}