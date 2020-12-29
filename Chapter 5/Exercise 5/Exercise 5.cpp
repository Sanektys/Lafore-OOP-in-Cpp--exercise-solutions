#include <iostream>
#include <conio.h>

inline long hms_to_secs(int hours, int minutes, int seconds);

int main() {
    do {
        std::cout << "\nEnter the current hours, minutes and seconds(hh:mm:ss): ";
        char colon;
        int hour;
        int minute;
        int second;
        std::cin >> hour >> colon >> minute >> colon >> second;

        std::cout << "Equivalent number of seconds: "
            << hms_to_secs(hour, minute, second) << std::endl;

        std::cout << "Try again(y/n)? ";
    } while (_getche() != 'n');

    return 0;
}

inline long hms_to_secs(int hours, int minutes, int seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}