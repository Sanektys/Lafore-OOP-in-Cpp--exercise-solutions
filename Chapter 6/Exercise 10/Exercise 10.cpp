#include <iostream>
#include <conio.h>

class Angle {
    public :
        Angle(short an, float mi, char di) : _angle(an), _minute(mi), _direction(di) {};

        void setAngle(bool isLongitude);
        void showAngle() const {
            std::cout << _angle << '\xF8' << _minute << "\' " << _direction;
        }

    private :
        short _angle;
        float _minute;
        char _direction;
};

void Angle::setAngle(bool isLongitude) {
    if (isLongitude) {
        std::cout << "Enter longitude:";
        do {
            std::cout << "\n...direction: ";
            _direction = _getche();
        } while (_direction != 'W' && _direction != 'E');
        do {
            std::cout << "\n...angle(0-180): ";
            std::cin >> _angle;
        } while (_angle < 0 || _angle > 180); 
    }
    else {
        std::cout << "Enter latitude:";
        do {
            std::cout << "\n...direction: ";
            _direction = _getche();
        } while (_direction != 'N' && _direction != 'S');
        do {
            std::cout << "\n...angle(0-90): ";
            std::cin >> _angle;
        } while (_angle < 0 || _angle > 90);
    }
    do {
        std::cout << "...minute(0-59.9): ";
        std::cin >> _minute;
    } while (_minute < 0 || _minute >= 60);
}

class Ship
{
    public :
        Ship() : _longCoord(0, 0.0f, 'W'), _latiCoord(0, 0.0f, 'N') {
            _count++;
            _serialNumber = _count;
        }

        void setShip() {
            _longCoord.setAngle(true);
            _latiCoord.setAngle(false);
        }
        void showShip() const;

    private :
        static int _count;
        int _serialNumber;
        Angle _longCoord;
        Angle _latiCoord;
};

int Ship::_count = 0;

void Ship::showShip() const {
    std::cout << "Ship serial number: " << _serialNumber << ", coordinates: ";
    _longCoord.showAngle();
    std::cout << ", ";
    _latiCoord.showAngle();
    std::cout << std::endl;
}

int main() {
    std::cout << "Enter the information of three ships\n";
    std::cout << "First ship:\n";
    Ship shipOne;
    shipOne.setShip();
    std::cout << "Second ship:\n";
    Ship shipTwo;
    shipTwo.setShip();
    std::cout << "Third ship:\n";
    Ship shipThree;
    shipThree.setShip();

    std::cout << "You entered the following information:\n";
    shipOne.showShip();
    shipTwo.showShip();
    shipThree.showShip();

    return 0;
}