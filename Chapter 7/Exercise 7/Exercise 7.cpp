#include <iostream>
#include <conio.h>
#include <iomanip>

class Money
{
    public :
        Money() : _money(0.0l) {}

        long double stringToDouble(char[]);

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

int main() {
    std::cout << "The program converts the monetary string "
                 "to a numeric floating point type\n";
    do {
        std::cout << "\nEnter a sum of money like $1,234,567.89\n";
        
        char string[32];
        std::cin >> string;
        
        std::cout << "A sum of money in numerical form: ";
        Money money;
        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
        std::cout << money.stringToDouble(string) << std::endl;
        
        std::cout << "Try another sum(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}