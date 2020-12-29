#include <iostream>
#include <conio.h>

struct Fraction
{
    int numeration;
    int denominator;
};

int main() {
    do {
        std::cout << "\nEnter two fractional operands and an operation on them:\n";
        Fraction fract1;
        Fraction fract2;
        char operand;
        char operation;
        std::cin >> fract1.numeration >> operand >> fract1.denominator >> operation
                 >> fract2.numeration >> operand >> fract2.denominator;

        Fraction fract3;
        switch (operation) {
            case '+' :
                fract3.numeration = fract1.numeration * fract2.denominator
                                    + fract2.numeration * fract1.denominator;
                fract3.denominator = fract1.denominator * fract2.denominator;
                std::cout << "Result: " << fract3.numeration << '/'
                          << fract3.denominator << std::endl;
                break;
            case '-' :
                fract3.numeration = fract1.numeration * fract2.denominator
                                    - fract2.numeration * fract1.denominator;
                fract3.denominator = fract2.denominator * fract2.denominator;
                std::cout << "Result: " << fract3.numeration << '/' 
                          << fract3.denominator << std::endl;
                break;
            case '*' :
                fract3.numeration = fract1.numeration * fract2.numeration;
                fract3.denominator = fract1.denominator * fract2.denominator;
                std::cout << "Result: " << fract3.numeration << '/' 
                          << fract3.denominator << std::endl;
                break;
            case '/' :
                fract3.numeration = fract1.numeration * fract2.denominator;
                fract3.denominator = fract1.denominator * fract2.numeration;
                std::cout << "Result: " << fract3.numeration << '/' 
                          << fract3.denominator << std::endl;
                break;
            default :
                std::cout << "Entered incorrect operation!\n";
        }

        std::cout << "Try another operation(y/n)? ";
    } while (_getche() != 'n');
    
    return 0;
}