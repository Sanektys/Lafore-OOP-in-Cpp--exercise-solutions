﻿#include <iostream>
#include <conio.h>

struct Fraction
{
    int numeration;
    int denominator;
};

Fraction add(Fraction fractOne, Fraction fractTwo);
Fraction sub(Fraction fractOne, Fraction fractTwo);
Fraction mul(Fraction fractOne, Fraction fractTwo);
Fraction div(Fraction fractOne, Fraction fractTwo);

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
                fract3 = add(fract1, fract2);
                std::cout << "Result: " << fract3.numeration << '/'
                          << fract3.denominator << std::endl;
                break;
            case '-' :
                
                fract3 = sub(fract1, fract2);
                std::cout << "Result: " << fract3.numeration << '/' 
                          << fract3.denominator << std::endl;
                break;
            case '*' :
                fract3 = mul(fract1, fract2);
                std::cout << "Result: " << fract3.numeration << '/' 
                          << fract3.denominator << std::endl;
                break;
            case '/' :               
                fract3 = div(fract1, fract2);
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

Fraction add(Fraction fractOne, Fraction fractTwo) {
    Fraction fraction;

    fraction.numeration  = fractOne.numeration * fractTwo.denominator
                           + fractTwo.numeration * fractOne.denominator;
    fraction.denominator = fractOne.denominator * fractTwo.denominator;

    return fraction;
}

Fraction sub(Fraction fractOne, Fraction fractTwo) {
    Fraction fraction;

    fraction.numeration  = fractOne.numeration * fractTwo.denominator
                           - fractTwo.numeration * fractOne.denominator;
    fraction.denominator = fractOne.denominator * fractTwo.denominator;

    return fraction;
}

Fraction mul(Fraction fractOne, Fraction fractTwo) {
    Fraction fraction;

    fraction.numeration  = fractOne.numeration * fractTwo.numeration;
    fraction.denominator = fractOne.denominator * fractTwo.denominator;
    
    return fraction;
}

Fraction div(Fraction fractOne, Fraction fractTwo) {
    Fraction fraction;

    fraction.numeration = fractOne.numeration * fractTwo.denominator;
    fraction.denominator = fractOne.denominator * fractTwo.numeration;

    return fraction;
}