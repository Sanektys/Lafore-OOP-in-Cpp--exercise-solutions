#include <iostream>
#include <math.h>

const float PI = 3.141592;

class Polar
{
    public :
        Polar() : _radius(0.0f), _angle(0.0f), _x(0.0f), _y(0.0f) {}
        Polar(float rad, float ang) : _radius(rad), _angle(ang), _x(0.0f), _y(0.0f) {
            while (_angle > 360)
                _angle -= 360;
        }

        void setCoord();
        void showCoord(){
            std::cout << _radius << ", " << _angle << (char)248;
        }

        Polar operator+(Polar coordTwo);

    private :
        void _polarToCarte() {
            _x = _radius * cos(_angle * PI / 180.0f);
            _y = _radius * sin(_angle * PI / 180.0f);
        }
        void _carteToPolar();

    private :
        float _radius;
        float _angle;
        float _x;
        float _y;
};

void Polar::setCoord() {
    std::cout << "Enter polar coordinate:\n";
    std::cout << "...radius: ";
    std::cin >> _radius;
    std::cout << "...angle: ";
    std::cin >> _angle;
    std::cin.get();

    while (_radius > 360)
        _radius -= 360;
}

void Polar::_carteToPolar() {
    _radius = (_y * _y) + (_x * _x);
    _radius = sqrt(_radius);

    if (_x == 0.0f && _y == 0.0f)
        _angle = 0.0f;
    else if (_x > 0.0f && _y >= 0.0f)
        _angle = atan2f(_y, _x);
    else if (_x > 0.0f && _y < 0.0f)
        _angle = atan2f(_y, _x) + 2.0f * PI;
    else if (_x < 0.0f)
        _angle = atan2f(_y, _x) + PI;
    else if (_x == 0.0f && _y > 0.0f)
        _angle = PI / 2.0f;
    else if (_x == 0.0f && _y < 0.0f)
        _angle = 3.0f * PI / 2.0f;

    _angle *= 180.0f / PI;
}

Polar Polar::operator+(Polar coordTwo) {
    _polarToCarte();
    coordTwo._polarToCarte();
    
    Polar temp;

    temp._x = _x + coordTwo._x;
    temp._y = _y + coordTwo._y;
    temp._carteToPolar();
    
    return temp;
}

int main() {
    std::cout << "The program adds up two entered polar coordinates\n";
    Polar coordOne;
    coordOne.setCoord();
    Polar coordTwo;
    coordTwo.setCoord();

    std::cout << "The result of adding the two coordinates is equal: ";
    Polar coordThree = coordOne + coordTwo;
    coordThree.showCoord();
    std::cout << std::endl;

    return 0;
}