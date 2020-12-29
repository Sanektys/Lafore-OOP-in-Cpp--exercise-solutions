#include <iostream>
#include <conio.h>

class Angle {
    public :
        Angle(short an, float mi, char di) : _angle(an), _minute(mi), _direction(di) {};

        void setAngle();
        void showAngle() const {
            std::cout << _angle << '\xF8' << _minute << "\' " << _direction;
        }

    private :
        short _angle;
        float _minute;
        char _direction;
};

void Angle::setAngle() {
    bool longitude = false;
    bool latitude = false;

    do {
        std::cout << "Enter direction: ";
        std::cin >> _direction;
        switch (_direction) {
            case 'N' :
            case 'S' :
                latitude = true;
                break;
            case 'E' :
            case 'W' :
                longitude = true;
                break;
        }
    } while (longitude == false && latitude == false);

    if (longitude) {
        std::cout << "Enter longitude:\n";    
        do {
            std::cout << "...angle(0-180): ";
            std::cin >> _angle;
        } while (_angle < 0 || _angle > 180); 
    }
    else if (latitude) {
        std::cout << "Enter latitude:\n";
        do {
            std::cout << "...angle(0-90): ";
            std::cin >> _angle;
        } while (_angle < 0 || _angle > 90);
    }
    do {
        std::cout << "...minute(0-59.9): ";
        std::cin >> _minute;
    } while (_minute < 0 || _minute >= 60);
}

int main() {
    Angle angle(20, 40.8f, 'E');
    angle.showAngle();

    do {
        std::cout << "\nEnter the value of the coordinates:\n";
        angle.setAngle();
        std::cout << "You entered: ";
        angle.showAngle();
        std::cout << "\nReply?(y/n): ";
    } while (_getche() != 'n');

    return 0;
}