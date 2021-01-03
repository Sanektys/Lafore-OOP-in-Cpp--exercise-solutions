#include <iostream>
#include <conio.h>

class Sterling
{
    public :
        Sterling() : _pounds(0), _shillings(0), _pence(0) {}
        Sterling(double decimalPounds);
        Sterling(int pou, int shi, int pen) : _pounds(pou), _shillings(shi), _pence(pen) {}

        void inputSterling();
        void showSterling() const {
            std::cout << _pounds << '.' << _shillings << '.' << _pence;
        }

        Sterling operator+(Sterling sumTwo) const {
            return Sterling((double)Sterling(_pounds, _shillings, _pence) + (double)sumTwo);
        }
        Sterling operator-(Sterling sumTwo) const {
            return Sterling((double)Sterling(_pounds, _shillings, _pence) - (double)sumTwo);
        }
        Sterling operator*(double sumTwo) const {
            return Sterling((double)Sterling(_pounds, _shillings, _pence) * sumTwo);
        }
        Sterling operator/(Sterling sumTwo) const {
            return Sterling((double)Sterling(_pounds, _shillings, _pence) / (double)sumTwo);
        }
        Sterling operator/(double sumTwo) const {
            return Sterling((double)Sterling(_pounds, _shillings, _pence) / sumTwo);
        }

        operator double() const;

        int getPounds() const { return _pounds; }
        int getShillings() const { return _shillings; }
        int getPence() const { return _pence; }

    protected :
        int _pounds;
        int _shillings;
        int _pence;
};

Sterling::Sterling(double decimalPounds) : _shillings(0) {
    _pounds = static_cast<int>(decimalPounds);
    decimalPounds -= _pounds;
    decimalPounds = (decimalPounds < 0) ? -decimalPounds : decimalPounds;
    decimalPounds *= 240.0;
    while (static_cast<int>(decimalPounds) >= 12) {
        _shillings++;
        decimalPounds -= 12.0;
    }
    _pence = static_cast<int>(decimalPounds);
    while (_shillings >= 20) {
        _pounds++;
        _shillings -= 20;
    }
}

void Sterling::inputSterling() {
    std::cout << "Enter the amount in sterling in format 100.19.11\n";
    char dot;
    bool incorrectShillings = false;
    bool incorrectPence = false;
    do {
        std::cin >> _pounds >> dot >> _shillings >> dot >> _pence;
        std::cin.get();

        incorrectShillings = _shillings < 0 || _shillings > 19;
        if (incorrectShillings)
            std::cout << "Wrong amount in shillings\n"
                         "(There should be no more than 19 of them)\n";
        incorrectPence = _pence < 0 || _pence > 11;
        if (incorrectPence)
            std::cout << "Wrong amount in pence\n"
                         "(There should be no more than 11 of them)\n";
        if (incorrectPence || incorrectShillings)
            std::cout << "Try to enter the amount again in format 100.19.11\n";
    } while (incorrectShillings || incorrectPence);
}

Sterling::operator double() const {
    double decimalPounds = _pounds;
    if (_pounds < 0)
        decimalPounds -= (_shillings * 12.0 + _pence) / 240.0;
    else
        decimalPounds += (_shillings * 12.0 + _pence) / 240.0;
    return decimalPounds;
}

///////////////////////////////////////////////////////////////////////////////

class Fraction
{
    public :
        Fraction() : _numerator(0), _denominator(0) {};
        Fraction(int num, int den) : _numerator(num), _denominator(den) {};

        void setFraction();
        void showFraction() const {
            std::cout << _numerator << '/' << _denominator;
        }

        int getNumerator() const { return _numerator; }
        int getDenominator() const { return _denominator; }

        Fraction lowterms();

        Fraction operator+(Fraction fractTwo);
        Fraction operator-(Fraction fractTwo);
        Fraction operator*(Fraction fractTwo);
        Fraction operator/(Fraction fractTwo);

        bool operator==(Fraction fractTwo) const;
        bool operator!=(Fraction fractTwo) const;

        operator double() const {
            if (_numerator == 0 || _denominator == 0)
                return 0.0;
            return (double)_numerator / _denominator;
        }

    protected :
        int _numerator;
        int _denominator;
};

void Fraction::setFraction() {
    std::cout << "Insert the fraction with the slash(example 3/4): ";
    char slash;
    std::cin >> _numerator >> slash >> _denominator;
}

Fraction Fraction::operator+(Fraction fractTwo) {
    _numerator   = _numerator * fractTwo._denominator
                   + fractTwo._numerator * _denominator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();

    return Fraction(_numerator, _denominator);
}

Fraction Fraction::operator-(Fraction fractTwo) {
    _numerator   = _numerator * fractTwo._denominator
                   - fractTwo._numerator * _denominator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();

    return Fraction(_numerator, _denominator);
}

Fraction Fraction::operator*(Fraction fractTwo) {
    _numerator   = _numerator * fractTwo._numerator;
    _denominator = _denominator * fractTwo._denominator;

    lowterms();

    return Fraction(_numerator, _denominator);
}

Fraction Fraction::operator/(Fraction fractTwo) {
    int numerator   = _numerator * fractTwo._denominator;
    int denominator = _denominator * fractTwo._numerator;

    _numerator = numerator;
    _denominator = denominator;

    lowterms();

    return Fraction(_numerator, _denominator);
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

///////////////////////////////////////////////////////////////////////////////

class SterFract : private Sterling, private Fraction
{
    public :
        SterFract() : Sterling(), Fraction() {}
        SterFract(double decimalPounds);
        SterFract(int pou, int shi, int pen, Fraction fra) : Sterling(pou, shi, pen), Fraction(fra) {}

        void setSterling();
        void showSterling() const {
            Sterling::showSterling();
            std::cout << '-';
            Fraction::showFraction();
        }

        SterFract operator+(SterFract sumTwo) const {
            return SterFract((double)SterFract(_pounds, _shillings, _pence, { _numerator, _denominator }) + (double)sumTwo);
        }
        SterFract operator-(SterFract sumTwo) const {
            return SterFract((double)SterFract(_pounds, _shillings, _pence, { _numerator, _denominator }) - (double)sumTwo);
        }
        SterFract operator*(double sumTwo) const {
            return SterFract((double)SterFract(_pounds, _shillings, _pence, { _numerator, _denominator }) * sumTwo);
        }
        SterFract operator/(SterFract sumTwo) const {
            return SterFract((double)SterFract(_pounds, _shillings, _pence, { _numerator, _denominator }) / (double)sumTwo);
        }
        SterFract operator/(double sumTwo) const {
            return SterFract((double)SterFract(_pounds, _shillings, _pence, { _numerator, _denominator }) / sumTwo);
        }

        operator double() const;

    private :

};

SterFract::SterFract(double decimalPounds) {
    Sterling tempSter(decimalPounds);
    decimalPounds -= (double)tempSter;
    
    decimalPounds = (decimalPounds < 0) ? -decimalPounds : decimalPounds;
    
    Fraction tempFract;
    while (decimalPounds + 0.000000001 >= (double)1/2 / 240.0) {
        decimalPounds -= (1.0 / 2.0) / 240.0;
        if (tempFract == Fraction(0, 0)) {
            tempFract = Fraction(1, 2);
            continue;
        }
        else
            tempFract = tempFract + Fraction(1, 2);
    }
    while (decimalPounds + 0.000000001 >= (double)1/4 / 240.0) {
        decimalPounds -= (1.0 / 4.0) / 240.0;
        if (tempFract == Fraction(0, 0)) {
            tempFract = Fraction(1, 4);
            continue;
        }
        else
            tempFract = tempFract + Fraction(1, 4);
    }
    while (decimalPounds + 0.000000001 >= (double)1/8 / 240.0) {
        decimalPounds -= (1.0 / 8.0) / 240.0;
        if (tempFract == Fraction(0, 0)) {
            tempFract = Fraction(1, 8);
            continue;
        }
        else
            tempFract = tempFract + Fraction(1, 8);
    }

    _pounds = tempSter.getPounds();
    _shillings = tempSter.getShillings();
    _pence = tempSter.getPence();

    while ((double)tempFract >= 1.0) {
        _pence++;
        tempFract = tempFract - Fraction(8, 8);
    }
    _numerator = tempFract.getNumerator();
    _denominator = tempFract.getDenominator();
    
    while (_pence >= 12) {
        _shillings++;
        _pence -= 12;
    }
    while (_shillings >= 20) {
        _pounds++;
        _shillings -= 20;
    }
}

void SterFract::setSterling() {
    Sterling::inputSterling();
    std::cout << "Enter the number of semifarth (1/8 of the pence) "
                 "in the range from 0 to 7.\n";
    int semifarth = 0;
    bool incorrectEnter = false;
    do {
        std::cin >> semifarth;
        incorrectEnter = semifarth < 0 || semifarth > 7;
        if (incorrectEnter)
            std::cout << "Incorrect enter of semifarth. Try again in range from 0 to 7: ";
    } while (incorrectEnter);

    _numerator = semifarth;
    _denominator = 8;
}

SterFract::operator double() const {
    double decimalPounds = Sterling::operator double();
    if (decimalPounds < 0)
        decimalPounds -= Fraction::operator double() / 240.0;
    else
        decimalPounds += Fraction::operator double() / 240.0;
    return decimalPounds;
}

///////////////////////////////////////////////////////////////////////////////

int main() {
    std::cout << "The program performs mathematical operations on the\n"
                 "obsolete form of recording pounds\n";
    do {
        std::cout << std::endl;

        SterFract sumOne;
        sumOne.setSterling();
        SterFract sumTwo;
        sumTwo.setSterling();

        std::cout << "Enter the required operation[+,-,*,/]: ";
        char operation;
        std::cin >> operation;

        SterFract result;
        switch (operation) {
            case '+' :
                result = sumOne + sumTwo;
                std::cout << "Result: ";
                result.showSterling();
                break;
            case '-' :
                result = sumOne - sumTwo;
                std::cout << "Result: ";
                result.showSterling();
                break;
            case '*' :
                result = sumOne * sumTwo;
                std::cout << "Result: ";
                result.showSterling();
                break;
            case '/' :               
                result = sumOne / sumTwo;
                std::cout << "Result: ";
                result.showSterling();
                break;
            default :
                std::cout << "Entered incorrect operation!\n";
        }
        std::cout << std::endl;
        std::cout << "\nTry another operation(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}