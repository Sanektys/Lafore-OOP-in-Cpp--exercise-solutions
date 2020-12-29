#include <iostream>
#include <iomanip>
#include <conio.h>

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
    _numerator   /= commonDivisor;
    _denominator /= commonDivisor;
}

int main() {
    std::cout << "The program summarizes the entered fractions "
                 "and displays the average result\n";
    const int SIZE = 20;
    Fraction fractions[SIZE];

    std::cout << "Enter some fractions(but no more than 20):\n";
    short count = 0;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Continue(y/n)? ";
        if (_getche() == 'n') {
            break;
        }
        std::cout << "\nEnter fraction " << i + 1 << ": ";
        fractions[i].setFraction();
        count++;
    }

    Fraction averFrac(fractions[0]);
    for (int i = 1; i < count; i++)
        averFrac.add(fractions[i]);
    Fraction divisor(count, 1);
    averFrac.div(divisor);

    std::cout << "\nThe average value: ";
    averFrac.showFraction();
    std::cout << std::endl;

    return 0;
}