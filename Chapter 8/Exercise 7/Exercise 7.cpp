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

        Fraction lowterms();

        Fraction operator+(Fraction fractTwo);
        Fraction operator-(Fraction fractTwo);
        Fraction operator*(Fraction fractTwo);
        Fraction operator/(Fraction fractTwo);

        bool operator==(Fraction fractTwo) const;
        bool operator!=(Fraction fractTwo) const;

    private :
        int _numerator;
        int _denominator;
};

void Fraction::setFraction() {
    std::cout << "Insert the fraction with the slash(example 3/4): ";
    char slash;
    std::cin >> _numerator >> slash >> _denominator;
}

Fraction Fraction::operator+(Fraction fractTwo) {
    int numerator   = _numerator * fractTwo._denominator
                      + fractTwo._numerator * _denominator;
    int denominator = _denominator * fractTwo._denominator;

    lowterms();

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator-(Fraction fractTwo) {
    int numerator   = _numerator * fractTwo._denominator
                      - fractTwo._numerator * _denominator;
    int denominator = _denominator * fractTwo._denominator;

    lowterms();

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator*(Fraction fractTwo) {
    int numerator   = _numerator * fractTwo._numerator;
    int denominator = _denominator * fractTwo._denominator;

    lowterms();

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator/(Fraction fractTwo) {
    int numerator   = _numerator * fractTwo._denominator;
    int denominator = _denominator * fractTwo._numerator;

    lowterms();

    return Fraction(numerator, denominator);
}

bool Fraction::operator==(Fraction fractTwo) const {
    bool conditionOne = _numerator == fractTwo._numerator;
    bool conditionTwo = _denominator == fractTwo._denominator;
    if (conditionOne && conditionTwo)
        return true;
    else
        return false;
}

bool Fraction::operator!=(Fraction fractTwo) const {
    bool conditionOne = _numerator != fractTwo._numerator;
    bool conditionTwo = _denominator != fractTwo._denominator;
    if (conditionOne && conditionTwo)
        return true;
    else
        return false;
}

Fraction Fraction::lowterms() {
    if (_numerator == 0 || _denominator == 0)
        return Fraction(0, 0);

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

    return Fraction(_numerator, _denominator);
}

int main() {
    do {
        std::cout << "Enter two fractional operands and an operation on them:\n"
                     "(enter 0/0 fraction for exit)\n";
        Fraction fractOne;
        Fraction fractTwo;
        fractOne.setFraction();
        fractTwo.setFraction();

        if (fractOne == Fraction(0, 0) || fractTwo == Fraction(0, 0))
            break;

        std::cout << "Enter the required operation[+,-,*,/]: ";
        char operation;
        std::cin >> operation;

        Fraction result;
        switch (operation) {
            case '+' :
                result = fractOne + fractTwo;
                std::cout << "Result: ";
                result.showFraction();
                break;
            case '-' :
                result = fractOne - fractTwo;
                std::cout << "Result: ";
                result.showFraction();
                break;
            case '*' :
                result = fractOne * fractTwo;
                std::cout << "Result: ";
                result.showFraction();
                break;
            case '/' :               
                result = fractOne / fractTwo;
                std::cout << "Result: ";
                result.showFraction();
                break;
            default :
                std::cout << "Entered incorrect operation!\n";
        }
        std::cout << std::endl;
        //std::cout << "\nTry another operation(y/n)? ";
    } while (true);

    return 0;
}