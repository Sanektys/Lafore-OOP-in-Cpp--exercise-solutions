#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

void swap(Time& valueOne, Time& valueTwo);

int main() {
    std::cout << "Enter the two time values in format 12:59:59\n"
              << "and the program will swap them\n\n";
    Time time1;
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

    Time time2;
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

    swap(time1, time2);

    std::cout << "Result of swiping of two time values:\n"
              << "First value: " << time1.hours << ':'
              << time1.minutes << ':' << time1.seconds << std::endl
              << "Second value: " << time2.hours << ':'
              << time2.minutes << ':' << time2.seconds << std::endl;

    return 0;
}

void swap(Time& valueOne, Time& valueTwo) {
    Time temp = valueOne;
    valueOne = valueTwo;
    valueTwo = temp;
}