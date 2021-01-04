#include "Airtime.h"


void Airtime::display() const {
    if (_hours < 10)
        std::cout << '0';
    std::cout << _hours << ':';
    if (_minutes < 10)
        std::cout << '0';
    std::cout << _minutes;
}

void Airtime::set() {
    char dummy = ':';
    std::cin.unsetf(std::ios::skipws);
    do {
        std::cout << "\nEnter time (in format 12:59): ";
        std::cin >> _hours >> dummy >> _minutes;
        if ((_hours < 0 || _hours > 12) || (_minutes < 0 || _minutes > 59))
            std::cin.clear(std::ios::failbit);
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect enter, try again   \\/ \\/ ";
            continue;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);
    std::cin.setf(std::ios::skipws);
}

Airtime Airtime::operator+(const Airtime& airtimeTwo) const {
    int tempH = _hours + airtimeTwo._hours;
    int tempM = _minutes + airtimeTwo._minutes;
    if (tempM >= 60) {
        tempH++;
        tempM -= 60;
    }

    return Airtime(tempH, tempM);
}