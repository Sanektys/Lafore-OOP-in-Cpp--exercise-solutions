#include <iostream>
#include <iomanip>

class Fraction
{
public:
    Fraction() : _numerator(0), _denominator(0) {};
    Fraction(int num, int den) : _numerator(num), _denominator(den) {};

    void setFraction();
    void showFraction() const;

    void add(Fraction fractTwo);
    void sub(Fraction fractTwo);
    void mul(Fraction fractTwo);
    void div(Fraction fractTwo);

    void lowterms();

private:
    int _numerator;
    int _denominator;
};

void Fraction::setFraction() {
    std::cout << "Insert the fraction with the slash(example 3/4): ";
    char slash;
    std::cin >> _numerator >> slash >> _denominator;
}

void Fraction::showFraction() const {
    std::cout << std::setw(3) << std::resetiosflags(std::ios::left)
              << _numerator << '/';
    std::cout << std::setw(3) << std::setiosflags(std::ios::left)
              << _denominator;
}

void Fraction::add(Fraction fractTwo) {
    _numerator = _numerator * fractTwo._denominator
        + fractTwo._numerator * _denominator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();
}

void Fraction::sub(Fraction fractTwo) {
    _numerator = _numerator * fractTwo._denominator
        - fractTwo._numerator * _denominator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();
}

void Fraction::mul(Fraction fractTwo) {
    _numerator = _numerator * fractTwo._numerator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();
}

void Fraction::div(Fraction fractTwo) {
    _numerator = _numerator * fractTwo._denominator;
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
    std::cout << "The program outputs an analogue of "
                 "an integer multiplication table for fractions\n";
    int denominator;
    do {
        std::cout << "Enter a denominator in the range from 1 to 10: ";
        std::cin >> denominator;
    } while (denominator < 1 || denominator > 10);

    for (int i = 0; i < denominator; i++) {
        if (i == 0)
            std::cout << std::setw(7) << ' ';
        else {
            Fraction fraction(i, denominator);
            fraction.showFraction();
        }
    }

    int line = 6 * denominator + denominator;
    std::cout << std::endl << std::setfill('-') << std::setw(line)
              << ' ' << std::setfill(' ') << std::endl;

    for (int i = 1; i < denominator; i++) {
        for (int j = 0; j < denominator; j++) {
            Fraction fractionOne(i, denominator);
            if (j == 0) {
                fractionOne.showFraction();
                continue;
            }
            
            Fraction fractionTwo(j, denominator);
            
            fractionOne.mul(fractionTwo);
            fractionOne.showFraction();
        }
        std::cout << std::endl;
    }

    return 0;
}