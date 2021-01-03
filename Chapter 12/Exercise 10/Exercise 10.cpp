#include <iostream>
#include <iomanip>

class Fraction
{
    public :
        Fraction() : _numerator(0), _denominator(0) {};
        Fraction(int num, int den) : _numerator(num), _denominator(den) {};

        void setFraction();
        void showFraction() const {
            std::cout << _numerator << '/' << _denominator;
        }

        Fraction lowterms(int numer, int denom) const;

        Fraction operator+(const Fraction& fractTwo) const;
        Fraction operator-(const Fraction& fractTwo) const;
        Fraction operator*(const Fraction& fractTwo) const;
        Fraction operator/(const Fraction& fractTwo) const;

        bool operator==(const Fraction& fractTwo) const;
        bool operator!=(const Fraction& fractTwo) const;

        friend std::istream& operator>>(std::istream& input, Fraction& fract);
        friend std::ostream& operator<<(std::ostream& output, Fraction& fract);

    private :
        int _numerator;
        int _denominator;
};

void Fraction::setFraction() {
    std::cout << "Insert the fraction with the slash(example 3/4): ";
    char slash;
    std::cin >> _numerator >> slash >> _denominator;
}

Fraction Fraction::operator+(const Fraction& fractTwo) const {
    int numerator   = _numerator * fractTwo._denominator
                      + fractTwo._numerator * _denominator;
    int denominator = _denominator * fractTwo._denominator;   

    return lowterms(numerator, denominator);
}

Fraction Fraction::operator-(const Fraction& fractTwo) const {
    int numerator   = _numerator * fractTwo._denominator
                      - fractTwo._numerator * _denominator;
    int denominator = _denominator * fractTwo._denominator;

    return lowterms(numerator, denominator);
}

Fraction Fraction::operator*(const Fraction& fractTwo) const {
    int numerator   = _numerator * fractTwo._numerator;
    int denominator = _denominator * fractTwo._denominator;

    return lowterms(numerator, denominator);
}

Fraction Fraction::operator/(const Fraction& fractTwo) const {
    int numerator   = _numerator * fractTwo._denominator;
    int denominator = _denominator * fractTwo._numerator;

    return lowterms(numerator, denominator);
}

bool Fraction::operator==(const Fraction& fractTwo) const {
    bool conditionOne = _numerator == fractTwo._numerator;
    bool conditionTwo = _denominator == fractTwo._denominator;
    if (conditionOne && conditionTwo)
        return true;
    else
        return false;
}

bool Fraction::operator!=(const Fraction& fractTwo) const {
    bool conditionOne = _numerator != fractTwo._numerator;
    bool conditionTwo = _denominator != fractTwo._denominator;
    if (conditionOne && conditionTwo)
        return true;
    else
        return false;
}

Fraction Fraction::lowterms(int numerator, int denominator) const {
    if (numerator == 0 || denominator == 0)
        return Fraction(0, 0);

    int tempNum;
    int tempDen;
    tempNum = (numerator < 0) ? -numerator : numerator;
    tempDen = (denominator < 0) ? -denominator : denominator;

    while (tempNum != 0) {
        if (tempNum < tempDen) {
            int temp = tempNum;
            tempNum = tempDen;
            tempDen = temp;
        }
        tempNum -= tempDen;
    }

    int commonDivisor = tempDen;
    numerator /= commonDivisor;
    denominator /= commonDivisor;

    return Fraction(numerator, denominator);
}

std::istream& operator>>(std::istream& input, Fraction& fract) {
    char slash;
    input >> fract._numerator >> slash >> fract._denominator;
    if (input.good() && fract._denominator == 0) {
        std::cerr << "Dividing by zero!\n";
        input.clear(std::ios::failbit);
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, Fraction& fract) {
    output << fract._numerator << '/' << fract._denominator;

    return output;
}

int main() {
    char answer[3];
    do {
        std::cout << "Enter two fractional operands(in format 99/99) and an operation on them[+,-,*,/]:\n";
          
        Fraction fractOne;
        Fraction fractTwo;
        char operation;

        std::cin.unsetf(std::ios::skipws);
        while (true) {
            std::cin >> fractOne >> operation >> fractTwo;
            if (!std::cin.good()) {
                std::cerr << "Incorrect entered expression! Try again: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
        std::cin.setf(std::ios::skipws);

        Fraction result;    
        switch (operation) {
            case '+' :
                result = fractOne + fractTwo;
                std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
                break;
            case '-' :
                result = fractOne - fractTwo;
                std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
                break;
            case '*' :
                result = fractOne * fractTwo;
                std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
                break;
            case '/' :               
                result = fractOne / fractTwo;
                std::cout << "Result: " << std::setfill('.') << std::setw(16) << ' ' << result;
                break;
            default :
                std::cout << "Entered incorrect operation!\n";
        }
        std::cout << std::endl;

        while (true) {
            std::cout << "Enter another expression(y/n)? ";
            std::cin.get(answer, 3);
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if (_strcmpi(answer, "y") && _strcmpi(answer, "n")) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter ONLY \"y\" or \"n\"\n";
                continue;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    } while (_strcmpi(answer, "n"));

    return 0;
}