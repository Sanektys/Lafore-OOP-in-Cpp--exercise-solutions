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

    private :
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

int main() {
    std::cout << "The program performs mathematical operations on the\n"
                 "obsolete form of recording pounds\n";
    do {
        std::cout << std::endl;

        Sterling sumOne;
        sumOne.inputSterling();
        Sterling sumTwo;
        sumTwo.inputSterling();

        std::cout << "Enter the required operation[+,-,*,/]: ";
        char operation;
        std::cin >> operation;

        Sterling result;
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