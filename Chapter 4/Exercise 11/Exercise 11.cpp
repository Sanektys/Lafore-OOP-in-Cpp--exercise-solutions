#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main() {
    std::cout << "Enter the two time values in format 12:59:59\n";
    Time time1;
    Time time2;
    char separator;
    bool correct = false;
    do {
        std::cout << "Enter the first value: ";
        std::cin >> time1.hours >> separator >> time1.minutes >> separator >> time1.seconds;
        bool hourExcess = time1.hours > 12 || time1.hours < 0;
        bool minuteExcess = time1.minutes > 59 || time1.minutes < 0;
        bool secondExcess = time1.seconds > 59 || time1.seconds < 0;
        if (hourExcess || minuteExcess || secondExcess)
            std::cout << "Exceeding one of the variables!\n";
        else
            correct = true;
    } while (!correct);

    correct = false;
    do {
        std::cout << "Enter the second value: ";
        std::cin >> time2.hours >> separator >> time2.minutes >> separator >> time2.seconds;
        bool hourExcess = time2.hours > 12 || time2.hours < 0;
        bool minuteExcess = time2.minutes > 59 || time2.minutes < 0;
        bool secondExcess = time2.seconds > 59 || time2.seconds < 0;
        if (hourExcess || minuteExcess || secondExcess)
            std::cout << "Exceeding one of the variables!\n";
        else
            correct = true;
    } while (!correct);

    int time1Seconds = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
    int time2Seconds = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;

    Time time3 = { 0, 0, 0 };
    int time3Seconds = time1Seconds + time2Seconds;
    while (time3Seconds >= 3600) {
        time3Seconds -= 3600;
        time3.hours++;
    }
    while (time3Seconds >= 60) {
        time3Seconds -= 60;
        time3.minutes++;
    }
    time3.seconds = time3Seconds;

    if (time3.hours > 24)
        time3.hours -= 24;

    std::cout << "The sum of two time values: " << time3.hours << ':'
              << time3.minutes << ':' << time3.seconds << std::endl;

    return 0;
}