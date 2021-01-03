#include <iostream>
#include <fstream>

class Distance
{
    public :
        Distance() : _feet(0), _inches(0.0f) {}
        Distance(float dist) {
            _feet = (int)dist;
            _inches = (dist - _feet) * 12.0f;
        }
        Distance(int fe, float in) : _feet(fe), _inches(in) {}

        void setDist();
        void showDist() {
            std::cout << _feet << "'-" << _inches << "\"";
        }

        void divDist(int divisor);

        Distance operator+(Distance&) const;
        Distance operator-(Distance&) const;
        Distance operator*(Distance&) const;

    private :
        int _feet;
        float _inches;
};

void Distance::setDist() {
    std::cout << "Enter distance in feet and inches:\n";
    std::cout << "...feet: ";
    std::cin.unsetf(std::ios::skipws);
    while (true) {
        std::cin >> _feet;
        if (!std::cin.good()) {
            std::cout << "Incorrect enter feet, try again: ";
            std::cin.clear();
            std::cin.ignore(10, '\n');
            continue;
        }
        else {
            std::cin.ignore(10, '\n');
            break;
        }
    }
    std::cout << "...inches: ";
    while (true) {
        std::cin >> _inches;
        if (!std::cin.good()) {
            std::cout << "Incorrect enter inches, try again: ";
            std::cin.clear();
            std::cin.ignore(10, '\n');
            continue;
        }
        else if (_inches > 12.0f || _inches < 0) {
            std::cout << "Incorrect enter inches. They can't be more than 12, try again: ";
            std::cin.ignore(10, '\n');
            continue;
        }
        else {
            std::cin.ignore(10, '\n');
            break;
        }
    }
    std::cin.setf(std::ios::skipws);
}

void Distance::divDist(int divisor) {
    float floatFeet = _feet + _inches / 12.0f;
    float temp = floatFeet /= divisor;
    _feet = static_cast<int>(floatFeet);
    _inches = (temp - _feet) * 12.0f;
}

Distance Distance::operator+(Distance& distTwo) const {
    int feet = _feet + distTwo._feet;
    float inches = _inches + distTwo._inches;
    if (inches >= 12.0f) {
        inches -= 12.0f;
        feet++;
    }

    return Distance(feet, inches);
}

Distance Distance::operator-(Distance& distTwo) const {
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

Distance Distance::operator*(Distance& distTwo) const {
    int feet = _feet;
    float inches = _inches;

    if (feet == 0 || distTwo._feet == 0)
        feet += distTwo._feet;
    else
        feet *= distTwo._feet;
    
    if (inches == 0 || distTwo._inches == 0)
        inches += distTwo._inches;
    else
        inches *= distTwo._inches;

    while (inches >= 12.0f) {
        feet++;
        inches -= 12.0f;
    }
    
    return Distance(feet, inches);
}

int main() {
    Distance distance;
    std::fstream file;
    char ch;

    file.open("Distance.dat", std::ios::binary
                              | std::ios::app
                              | std::ios::in
                              | std::ios::out);
    std::cout << "Enter distance in format 999'-11.9\"\n";
    do {
        distance.setDist();
        file.write((char*)&distance, sizeof(distance));
        
        std::cout << "Continue enter(y/n)? ";
        std::cin.get(ch);
        std::cin.ignore(2, '\n');
    } while (ch != 'n');

    file.seekg(0);
    std::cout << std::endl;

    short count = 1;
    file.read((char*)&distance, sizeof(distance));
    while (!file.eof()) {
        std::cout << "Distance " << count << ":  ";
        distance.showDist();
        std::cout << std::endl;
        file.read((char*)&distance, sizeof(distance));
        count++;
    }

    //int test1;
    //float test2;
    //double test3;
    //std::cout << "\n\nSize of distance: " << sizeof(distance) << std::endl;
    //std::cout << "Size of short: " << sizeof(count) << std::endl;
    //std::cout << "Size of integer: " << sizeof(test1) << std::endl;
    //std::cout << "Size of float: " << sizeof(test2) << std::endl;
    //std::cout << "Size of double: " << sizeof(test3) << std::endl;

    return 0;
}