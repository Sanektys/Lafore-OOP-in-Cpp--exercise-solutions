#include <iostream>
#include <iomanip>

class Money
{
    public :
        Money() : _money(0.0l) {}
        explicit Money(long double money) : _money(money) {}
        explicit Money(char string[]) { _stringToDouble(string); }

        void setMoney();
        void getMoney() const {
            _doubleToString(_money);
        }

        friend Money round(Money);

        Money operator+(const Money& sumTwo) const;
        Money operator-(const Money& sumTwo) const;
        Money operator*(long double pricePerTime) const;
        long double operator/(const Money& sumTwo) const;
        Money operator/(long double numberOfProduct) const;
        friend Money operator*(long double number, const Money& sum);
        friend Money operator/(long double number, const Money& sum);

        friend std::ostream& operator<<(std::ostream& out, Money& money);
        friend std::istream& operator>>(std::istream& in, Money& money);

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

Money Money::operator+(const Money& sumTwo) const {
    if (_outOfRange(_money, sumTwo._money))
        return Money(0.0l);
    
    long double sum = _money + sumTwo._money;

    return Money(sum);
}

Money Money::operator-(const Money& sumTwo) const {
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

long double Money::operator/(const Money& sumTwo) const {
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

Money operator*(long double number, const Money& sum) {
    if (sum._outOfRange(sum._money))
        return Money(0.0l);

    return Money(number * sum._money);
}

Money operator/(long double number, const Money& sum) {
    if (sum._outOfRange(sum._money))
        return Money(0.0l);

    return Money(number / sum._money);
}

Money round(Money money) {
    long double temp = money._money;
    temp -= (int)money._money;
    temp = (temp < 0) ? -temp : temp;

    long double result = 0.0;
    if (temp >= 0.5)
        if (money._money < 0)
            result = money._money + temp - 1;
        else
            result = money._money - temp + 1;
    else
        if (money._money < 0)
            result = money._money + temp;
        else
            result = money._money - temp;

    return Money(result);
}

std::ostream& operator<<(std::ostream& output, Money& money) {
    money.getMoney();

    return output;
}

std::istream& operator>>(std::istream& input, Money& money) {
    std::cout << "Enter a sum of money in the format $1,234,567.89 : ";
    std::string string;
    input.unsetf(std::ios::skipws);
    while (true) {
        input >> string;
        if (!input.good()) {
            std::cerr << "Incorrect entered sum of money. Try again: ";
            input.clear();
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    input.setf(std::ios::skipws);
    money._stringToDouble((char*)string.c_str());

    return input;
}

int main() {
    char answer[3];
    do {
        Money moneyOne;
        Money moneyTwo;
        std::cin >> moneyOne >> moneyTwo;
        std::cout << moneyOne << std::endl
                  << moneyTwo << std::endl;

        while (true) {
            std::cout << "Enter another sum(y/n)? ";
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