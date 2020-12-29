#include <iostream>

struct phone
{
    short townCode;
    short stationNumber;
    short abonentNumber;
};

int main() {
    phone phoneOne = { 212, 767, 8900 };

    std::cout << "Enter city code, station number, and abonent number:\n";
    phone phoneTwo;
    std::cin >> phoneTwo.townCode >> phoneTwo.stationNumber >> phoneTwo.abonentNumber;

    std::cout << "My phone number: " << '(' << phoneOne.townCode << ')' << ' '
              << phoneOne.stationNumber << '-' << phoneOne.abonentNumber << std::endl;
    std::cout << "Your phone number: " << '(' << phoneTwo.townCode << ')' << ' '
              << phoneTwo.stationNumber << '-' << phoneTwo.abonentNumber << std::endl;

    return 0;
}