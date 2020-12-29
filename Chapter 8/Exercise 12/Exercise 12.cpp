#include <iostream>
#include <conio.h>


class Money
{
    public :
        Money() : _money(0.0l) {}
        explicit Money(long double money) : _money(money) {}
        explicit Money(char string[]) { _stringToDouble(string); }

        void setMoney();
        long double getMoney() const { return _money; }
        void showMoney() const { _doubleToString(_money); }

        Money operator+(Money sumTwo) const;
        Money operator-(Money sumTwo) const;
        Money operator*(long double pricePerTime) const;
        long double operator/(Money sumTwo) const;
        Money operator/(long double numberOfProduct) const;

        //operator Sterling() const;
        //operator double() const { return double(_money); }

    private :
        long double _stringToDouble(char[]);
        void _doubleToString(long double) const;
        char _numberToChar(int number) const;

        bool _outOfRange(long double firstSum,
                         long double secondSum = 0.0l) const; 

    private :
        long double _money;
};

void Money::setMoney() {
    std::cout << "Enter a sum of money in the format $1,234,567.89 : ";
    char string[32];
    std::cin.get(string, 32);
    std::cin.get();
    _stringToDouble(string);
}

long double Money::_stringToDouble(char string[]) {
    short size = 0;
    short point = 0;
    while (string[size] != '\0') {
        if (string[size] == '.')
            point = size;
        size++;
    }

    if (size > 32) {
        std::cout << "Money amount is too lenght";
        return 0;
    }

    if (point == 0)
        point = size;

    long double multiplier = 0.1l;
    for (int i = point + 1; i < size; i++) {
        _money += (static_cast<long long>(string[i]) - 48) * multiplier;
        multiplier *= 0.1l;
    }

    multiplier = 1.0l;
    for (int i = point - 1; i >= 0; i--) {
        switch (string[i]) {
            case '0' :
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
                _money += (static_cast<__int64>(string[i]) - 48) * multiplier;
                multiplier *= 10.0l;
        }
    }

    for (int i = 0; i < size; i++) {
        if (string[i] == '$')
            break;
        if (string[i] == '-')
            _money *= -1;
    }

    return _money;
}

char Money::_numberToChar(int number) const {
    number = (number < 0) ? -number : number;
    char symbol = '0';
    switch (number) {
        case 0:
            symbol = '0';
            break;
        case 1:
            symbol = '1';
            break;
        case 2:
            symbol = '2';
            break;
        case 3:
            symbol = '3';
            break;
        case 4:
            symbol = '4';
            break;
        case 5:
            symbol = '5';
            break;
        case 6:
            symbol = '6';
            break;
        case 7:
            symbol = '7';
            break;
        case 8:
            symbol = '8';
            break;
        case 9:
            symbol = '9';
    }
    
    return symbol;
}

void Money::_doubleToString(long double money) const {
    if (money > 9999999999999999.99l) {
        std::cout << "Too big a monetary value";
        return;
    }

    short lenght = 0;
    long double temp = money;
    while (static_cast<long long>(temp) != 0) {
        temp /= 10;
        lenght++;
    }

    if (lenght > 20) {
        std::cout << "Money amount is too lenght";
        return;
    }

    char string[32];
    short startIndex;
    
    if (money < 0) {
        string[0] = '-';
        string[1] = '$';
        startIndex = 2;
    }
    else {
        string[0] = '$';
        startIndex = 1;
    }

    if (lenght == 0) {
        lenght++;
        string[lenght] = '0';
    }
    else {
        long long excessInt = 0;
        short comma = lenght;
        while (comma > 3)
            comma -= 3;
        for (int i = startIndex; i < startIndex + lenght; i++) {
            if (i == startIndex + comma) {
                string[i] = ',';
                lenght++;
                comma += 4;
                continue;
            }
            long long temp = static_cast<long long>(money);
            for (int j = lenght + (startIndex - 1) - i; j > 0; j--)
                temp /= 10;
            string[i] = _numberToChar(int(temp - excessInt));
            excessInt = static_cast<long long>(temp) * 10;
        }
    }

    if (startIndex == 1)
        lenght++;
    else if (startIndex == 2)
        lenght += 2;
    string[lenght] = '.';
    lenght++;
    
    temp = money - static_cast<long long>(money) + 0.001l;
    for (int i = lenght; i < lenght + 2; i++) {
        temp *= 10;
        string[i] = _numberToChar(static_cast<int>(temp));
        temp -= static_cast<long long>(temp);
    }

    string[lenght + 2] = '\0';

    std::cout << string;
}

bool Money::_outOfRange(long double firstSum, long double secondSum) const{
    bool conditionOne = firstSum > 9999999999999999.99l;
    bool conditionTwo = secondSum > 9999999999999999.99l;
    if (conditionOne || conditionTwo) {
        std::cout << "One of the monetary variables is too big";
        return true;
    }
    else
        return false;
}

Money Money::operator+(Money sumTwo) const {
    if (_outOfRange(_money, sumTwo._money))
        return Money(0.0l);

    long double sum = _money + sumTwo._money;

    return Money(sum);
}

Money Money::operator-(Money sumTwo) const {
    if (_outOfRange(_money, sumTwo._money))
        return Money(0.0l);

    long double sum = _money - sumTwo._money;

    return Money(sum);
}

Money Money::operator*(long double pricePerTime) const {
    if (_outOfRange(_money))
        return Money(0.0l);

    long double sum = _money * pricePerTime;

    return Money(sum);
}

long double Money::operator/(Money sumTwo) const {
    if (_outOfRange(_money, sumTwo._money))
        return 0.0l;

    long double sum = _money / sumTwo._money;

    return sum;
}

Money Money::operator/(long double numberOfProduct) const {
    if (_outOfRange(_money))
        return Money(0.0l);

    long double sum = _money / numberOfProduct;

    return Money(sum);
}

///////////////////////////////////////////////////////////////////////////////

class Sterling
{
    public :
        Sterling() : _pounds(0), _shillings(0), _pence(0) {}
        Sterling(double decimalPounds) : _shillings(0) { _decimalToLegacy(decimalPounds); }
        Sterling(Money money);
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
        operator Money() const { return Money((double)Sterling(_pounds, _shillings, _pence) * 50.0); }

    private :
        void _decimalToLegacy(double decimalPounds);

    private :
        int _pounds;
        int _shillings;
        int _pence;
};

void Sterling::_decimalToLegacy(double decimalPounds) {
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

Sterling::Sterling(Money money) : _shillings(0) {
    if (money.getMoney() == 0) {
        _pounds = 0;
        _pence = 0;
    }
    else
        _decimalToLegacy(money.getMoney() / 50.0);
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
    std::cout << "The program recalculates monetary amounts\n"
                 "(sterlings -> dollars; dollars -> sterlings)\n";
    do {
        std::cout << "\nEnter monetary amount in dollars...\n";
        Money dollars;
        dollars.setMoney();

        std::cout << "Entered monetary amount in sterlings: ";
        Sterling sterlings = dollars;
        sterlings.showSterling();
        std::cout << std::endl;

        std::cout << "\nEnter monetary amount in sterlings...\n";
        sterlings.inputSterling();

        std::cout << "Entered monetary amount in dollars: ";
        dollars = sterlings;
        dollars.showMoney();
       
        std::cout << std::endl;
        std::cout << "\nWant to enter another sum(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}