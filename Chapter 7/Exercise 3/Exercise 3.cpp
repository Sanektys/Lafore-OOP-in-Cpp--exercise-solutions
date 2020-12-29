#include <iostream>
#include <conio.h>

class Distance
{
    public :
        Distance() : _feet(0), _inches(0) {};

        void setDist();
        void showDist() const {
            std::cout << _feet << "\'-" << _inches << '\"';
        }

        void addDist(Distance distTwo);
        void divDist(int divisor);

    private :
        int _feet;
        float _inches;
};

void Distance::setDist() {
    std::cout << "Enter distance in feet and inches:\n";
    std::cout << "...feet: ";
    std::cin >> _feet;
    std::cout << "...inches: ";
    std::cin >> _inches;
}

void Distance::addDist(Distance distTwo) {
    _inches += distTwo._inches;
    if (_inches >= 12.0f) {
        _inches -= 12.0f;
        _feet++;
    }
    _feet += distTwo._feet;
}

void Distance::divDist(int divisor) {
    float floatFeet = _feet + _inches / 12.0f;
    float temp = floatFeet /= divisor;
    _feet = static_cast<int>(floatFeet);
    _inches = (temp - _feet) * 12.0f;
}

int main() {
    Distance distance[100];

    short count = 0;
    std::cout << "Enter several distance values (up to a 100 values) "
                 "and the program will display the average value\n";
    do {
        if (count >= 99)
            break;
        std::cout << "Continue(y/n)? ";
        if (_getche() == 'n')
            break;

        count++;
        std::cout << "\nValue " << count << std::endl;
        distance[count - 1].setDist();
    } while (true);
    
    int total = count;
    std::cout << std::endl;

    Distance totalDist;
    while (count - 1 >= 0) {
        totalDist.addDist(distance[count - 1]);
        count--;
    }
    totalDist.divDist(total);

    std::cout << "The average value: ";
    totalDist.showDist();
    std::cout << std::endl;

    return 0;
}