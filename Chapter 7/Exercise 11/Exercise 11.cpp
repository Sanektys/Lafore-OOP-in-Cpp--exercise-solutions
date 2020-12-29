#include <iostream>
#include <conio.h>
#include <iomanip>

class Money
{
    public :
        Money() : _money(0.0l) {}

        long double stringToDouble(char[]);
        void doubleToString(long double);

    private :
        char _numberToChar(int number) const;

    private :
        long double _money;
};

long double Money::stringToDouble(char string[]) {
    short size = 0;
    short point = 0;
    while (string[size] != '\0') {
        if (string[size] == '.')
            point = size;
        size++;
    }
    if (point == 0)
        point = size;

    long double multiplier = 0.1l;
    for (int i = point + 1; i < size; i++) {
        _money += (static_cast<__int64>(string[i]) - 48) * multiplier;
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

    return _money;
}

char Money::_numberToChar(int number) const {
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

void Money::doubleToString(long double money) {
    if (money > 9999999999999999.99l) {
        std::cout << "Too big a monetary value\n";
        return;
    }

    short length = 0;
    long double temp = money;
    while (static_cast<long long>(temp) != 0) {
        temp /= 10;
        length++;
    }

    if (length > 20) {
        std::cout << "Money amount is too lenght\n";
        return;
    }

    char string[32];
    string[0] = '$';

    if (length == 0) {
        length = 1;
        string[length] = '0';
    }
    else {
        int excessInt = 0;
        short comma = length;
        while (comma > 3)
            comma -= 3;
        for (int i = 1; i <= length; i++) {
            if (i == comma + 1) {
                string[i] = ',';
                length++;
                comma += 4;
                continue;
            }
            temp = static_cast<long long>(money);
            for (int j = length - i; j > 0; j--)
                temp /= 10;
            string[i] = _numberToChar(static_cast<long long>(temp) - excessInt);
            excessInt = static_cast<long long>(temp) * 10;
        }
    }
    
    length++;
    string[length] = '.';
    length++;
    
    temp = money - static_cast<long long>(money) + 0.001l;
    for (int i = length; i < length + 2; i++) {
        temp *= 10;
        string[i] = _numberToChar(static_cast<long long>(temp));
        temp -= static_cast<long long>(temp);
    }

    string[length + 2] = '\0';

    std::cout << string;
}

int main() {
    std::cout << "The program converts the amount of money as a "
                 "floating point number into a string array\n";
    do {
        std::cout << "\nEnter a sum of money like 1234567.89\n";
        
        double sumOfMoney;
        std::cin >> sumOfMoney;
        
        std::cout << "A sum of money in string array form: ";
        Money money;
        money.doubleToString(sumOfMoney);
        std::cout << std::endl;
        
        std::cout << "Try another sum(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}