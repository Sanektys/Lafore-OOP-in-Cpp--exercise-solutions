#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main() {
    std::cout << "Enter current time in format hh/mm/ss: ";
    char slash;
    Time time;
    std::cin >> time.hours >> slash >> time.minutes >> slash >> time.seconds;
    
    int totalSec = time.hours * 3600 + time.minutes * 60 + time.seconds;
    std::cout << "Seconds in total: " << totalSec << std::endl;

    return 0;
}