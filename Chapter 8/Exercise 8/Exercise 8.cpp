#include <iostream>
#include <conio.h>
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

        Money operator+(Money sumTwo) const;
        Money operator-(Money sumTwo) const;
        Money operator*(long double pricePerTime) const;
        long double operator/(Money sumTwo) const;
        Money operator/(long double numberOfProduct) const;

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


int main() {
    std::cout << "The program makes various calculations based "
                 "on a pair of input amounts\n";
    do {
        std::cout << std::endl;

        Money firstSum;
        firstSum.setMoney();
        Money secondSum;
        secondSum.setMoney();

        std::cout << "Enter number of items: ";
        double items;
        std::cin >> items;
        std::cin.get();

        Money sumOfMoney = firstSum + secondSum;
        std::cout << "The sum of two values: ";
        sumOfMoney.getMoney();
        std::cout << std::endl;

        Money diffOfMoney = firstSum - secondSum;
        std::cout << "Difference of two values: ";
        diffOfMoney.getMoney();
        std::cout << std::endl;

        Money totalPrice = sumOfMoney * items;
        std::cout << "Total price for all items: ";
        totalPrice.getMoney();
        std::cout << std::endl;

        items = totalPrice / sumOfMoney;
        std::cout << "Total number of items: " << (int)items << std::endl;

        diffOfMoney = totalPrice / items;
        std::cout << "Price of one item: ";
        diffOfMoney.getMoney();
        std::cout << std::endl;
       
        std::cout << "Want to enter another amount of money(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}