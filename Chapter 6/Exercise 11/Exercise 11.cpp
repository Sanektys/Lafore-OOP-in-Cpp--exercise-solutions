#include <iostream>
#include <conio.h>

class Fraction
{
    public :
        Fraction() : _numerator(0), _denominator(0) {};
        Fraction(int num, int den) : _numerator(num), _denominator(den) {};

        void setFraction();
        void showFraction() const {
            std::cout << _numerator << '/' << _denominator;
        }

        void add(Fraction fractTwo);
        void sub(Fraction fractTwo);
        void mul(Fraction fractTwo);
        void div(Fraction fractTwo);

        void lowterms();

    private :
        int _numerator;
        int _denominator;
};

void Fraction::setFraction() {
    std::cout << "Insert the fraction with the slash(example 3/4): ";
    char slash;
    std::cin >> _numerator >> slash >> _denominator;
}

void Fraction::add(Fraction fractTwo) {
    _numerator   = _numerator * fractTwo._denominator
                   + fractTwo._numerator * _denominator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();
}

void Fraction::sub(Fraction fractTwo) {
    _numerator   = _numerator * fractTwo._denominator
                   - fractTwo._numerator * _denominator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();
}

void Fraction::mul(Fraction fractTwo) {
    _numerator   = _numerator * fractTwo._numerator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();
}

void Fraction::div(Fraction fractTwo) {
    _numerator   = _numerator * fractTwo._denominator;
    _denominator = _denominator * fractTwo._numerator;

    lowterms();
}

void Fraction::lowterms() {
    if (_numerator == 0 || _denominator == 0)
        return;

    int tempNum;
    int tempDen;
    tempNum = (_numerator < 0) ? -_numerator : _numerator;
    tempDen = (_denominator < 0) ? -_denominator : _denominator;

    while (tempNum != 0) {
        if (tempNum < tempDen) {
            int temp = tempNum;
            tempNum = tempDen;
            tempDen = temp;
        }
        tempNum -= tempDen;
    }

    int commonDivisor = tempDen;
    _numerator /= commonDivisor;
    _denominator /= commonDivisor;
}

int main() {
    do {
        std::cout << "\nEnter two fractional operands and an operation on them:\n";
        Fraction fractOne;
        Fraction fractTwo;
        fractOne.setFraction();
        fractTwo.setFraction();
        std::cout << "Enter the required operation[+,-,*,/]: ";
        char operation;
        std::cin >> operation;

        switch (operation) {
            case '+' :
                fractOne.add(fractTwo);
                std::cout << "Result: ";
                fractOne.showFraction();
                break;
            case '-' :
                fractOne.sub(fractTwo);
                std::cout << "Result: ";
                fractOne.showFraction();
                break;
            case '*' :
                fractOne.mul(fractTwo);
                std::cout << "Result: ";
                fractOne.showFraction();
                break;
            case '/' :               
                fractOne.div(fractTwo);
                std::cout << "Result: ";
                fractOne.showFraction();
                break;
            default :
                std::cout << "Entered incorrect operation!\n";
        }

        std::cout << "\nTry another operation(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}