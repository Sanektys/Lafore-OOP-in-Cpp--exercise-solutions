#pragma once

#include <iostream>
#include <iomanip>


template <typename T>
class Fraction
{
    public :
        Fraction() : _numerator(0), _denominator(0) {};
        Fraction(T num, T den) : _numerator(num), _denominator(den) {};

        void setFraction();
        void showFraction() const {
            std::cout << _numerator << '/' << _denominator;
        }

        Fraction lowterms(T numer, T denom) const;

        Fraction operator+(const Fraction& fractTwo) const;
        Fraction operator-(const Fraction& fractTwo) const;
        Fraction operator*(const Fraction& fractTwo) const;
        Fraction operator/(const Fraction& fractTwo) const;

        bool operator==(const Fraction& fractTwo) const;
        bool operator!=(const Fraction& fractTwo) const;

        template <typename T> friend std::istream& operator>>(std::istream& input, Fraction<T>& fract);
        template <typename T> friend std::ostream& operator<<(std::ostream& output, Fraction<T>& fract);

    private :
        T _numerator;
        T _denominator;
};

template <typename T>
void Fraction<T>::setFraction() {
    std::cin.unsetf(std::ios::skipws);
    do {
        std::cout << "Insert the fraction with the slash(example 3/4): ";
        char slash = '/';
        std::cin >> _numerator >> slash >> _denominator;

        if (!std::cin.good()) {
            std::cin.clear();
            std::cout << "Incorrect entered numerator/denominator!\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);
    std::cin.setf(std::ios::skipws);
}

template <typename T>
Fraction<T> Fraction<T>::operator+(const Fraction& fractTwo) const {
    T numerator   = _numerator * fractTwo._denominator
                    + fractTwo._numerator * _denominator;
    T denominator = _denominator * fractTwo._denominator;   

    return lowterms(numerator, denominator);
}

template <typename T>
Fraction<T> Fraction<T>::operator-(const Fraction& fractTwo) const {
    T numerator   = _numerator * fractTwo._denominator
                    - fractTwo._numerator * _denominator;
    T denominator = _denominator * fractTwo._denominator;

    return lowterms(numerator, denominator);
}

template <typename T>
Fraction<T> Fraction<T>::operator*(const Fraction& fractTwo) const {
    T numerator   = _numerator * fractTwo._numerator;
    T denominator = _denominator * fractTwo._denominator;

    return lowterms(numerator, denominator);
}

template <typename T>
Fraction<T> Fraction<T>::operator/(const Fraction& fractTwo) const {
    T numerator   = _numerator * fractTwo._denominator;
    T denominator = _denominator * fractTwo._numerator;

    return lowterms(numerator, denominator);
}

template <typename T>
bool Fraction<T>::operator==(const Fraction& fractTwo) const {
    bool conditionOne = _numerator == fractTwo._numerator;
    bool conditionTwo = _denominator == fractTwo._denominator;
    if (conditionOne && conditionTwo)
        return true;
    else
        return false;
}

template <typename T>
bool Fraction<T>::operator!=(const Fraction& fractTwo) const {
    bool conditionOne = _numerator != fractTwo._numerator;
    bool conditionTwo = _denominator != fractTwo._denominator;
    if (conditionOne && conditionTwo)
        return true;
    else
        return false;
}

template <typename T>
Fraction<T> Fraction<T>::lowterms(T numerator, T denominator) const {
    if (numerator == 0 || denominator == 0)
        return Fraction(0, 0);

    T tempNum;
    T tempDen;
    tempNum = (numerator < 0) ? -numerator : numerator;
    tempDen = (denominator < 0) ? -denominator : denominator;

    while (tempNum != 0) {
        if (tempNum < tempDen) {
            T temp = tempNum;
            tempNum = tempDen;
            tempDen = temp;
        }
        tempNum -= tempDen;
    }

    T commonDivisor = tempDen;
    numerator /= commonDivisor;
    denominator /= commonDivisor;

    return Fraction(numerator, denominator);
}

template <typename T>
std::istream& operator>>(std::istream& input, Fraction<T>& fract) {
    char slash = '/';
    input >> fract._numerator >> slash >> fract._denominator;

    if (input.good() && fract._denominator == 0) {
        std::cerr << "Dividing by zero! ";
        input.clear(std::ios::failbit);
    }
    else if (!input.good())
        std::cerr << "Incorrect entered numerator/denominator! ";

    return input;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, Fraction<T>& fract) {
    output << fract._numerator << '/' << fract._denominator;

    return output;
}