#include <iostream>
#include <conio.h>

class Fraction
{
    public :
        Fraction() : _numeration(0), _denominator(0) {};

        void setFraction();
        void showFraction() const {
            std::cout << _numeration << '/' << _denominator;
        }

        void addFraction(Fraction fractTwo);

    private :
        int _numeration;
        int _denominator;
};

void Fraction::setFraction() {
    std::cout << "Insert the fraction with the slash(example 3/4): ";
    char slash;
    std::cin >> _numeration >> slash >> _denominator;
}

void Fraction::addFraction(Fraction fractTwo) {
    _numeration = _numeration * fractTwo._denominator
                  + fractTwo._numeration * _denominator;
    _denominator = _denominator * fractTwo._denominator;
}

int main() {
    do {
        std::cout << "\nEnter two fraction and the program will add them up\n";
        std::cout << "First - ";
        Fraction fractionOne;
        fractionOne.setFraction();
        std::cout << "Second - ";
        Fraction fractionTwo;
        fractionTwo.setFraction();

        fractionOne.addFraction(fractionTwo);
        std::cout << "The result of the addition: ";
        fractionOne.showFraction();
        std::cout << "\nRepeat(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}