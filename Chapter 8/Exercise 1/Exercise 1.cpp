#include <iostream>

class Distance
{
    public :
        Distance() : _feet(0), _inches(0) {};
        Distance(int ft, float in) : _feet(ft), _inches(in) {}

        void setDist();
        void showDist() const {
            std::cout << _feet << "\'-" << _inches << '\"';
        }

        void divDist(int divisor);

        Distance operator+(Distance) const;
        Distance operator-(Distance) const;

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

void Distance::divDist(int divisor) {
    float floatFeet = _feet + _inches / 12.0f;
    float temp = floatFeet /= divisor;
    _feet = static_cast<int>(floatFeet);
    _inches = (temp - _feet) * 12.0f;
}

Distance Distance::operator+(Distance distTwo) const {
    int feet = _feet + distTwo._feet;
    float inches = _inches + distTwo._inches;
    if (inches >= 12.0f) {
        inches -= 12.0f;
        feet++;
    }

    return Distance(feet, inches);
}

Distance Distance::operator-(Distance distTwo) const {
    float feetOne = _feet + _inches / 12.0f;
    float feetTwo = distTwo._feet + distTwo._inches / 12.0f;
    if (feetTwo > feetOne) {
        std::cout << "You can't subtract more from less.\n";
        return Distance(0, 0.0f);
    }

    float resultFeet = feetOne - feetTwo;
    int feet = static_cast<int>(resultFeet);
    float inches = (resultFeet - feet) * 12.0f;
    if (inches >= 12.0f) {
        inches -= 12.0f;
        feet++;
    }

    return Distance(feet, inches);
}

int main() {
    Distance distOne;
    distOne.setDist();

    Distance distTwo(11, 6.25);

    Distance distThree = distOne + distTwo;
    Distance distFour = distOne + distTwo + distThree;

    std::cout << "Distance one  = ";
    distOne.showDist();
    std::cout << "\nDistance two  = ";
    distTwo.showDist();
    std::cout << "\nDistance three = ";
    distThree.showDist();
    std::cout << "\nDistance four  = ";
    distFour.showDist();
    std::cout << std::endl;

    distOne = distThree - distFour;
    distTwo = distFour - distThree - distTwo;
    distFour = distThree - distTwo;

    std::cout << "\nDistance one  = ";
    distOne.showDist();
    std::cout << "\nDistance two  = ";
    distTwo.showDist();
    std::cout << "\nDistance three = ";
    distThree.showDist();
    std::cout << "\nDistance four  = ";
    distFour.showDist();

    return 0;
}