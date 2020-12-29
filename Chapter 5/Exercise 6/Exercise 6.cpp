#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

inline long time_to_secs(Time time);
Time secs_to_time(long seconds);

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

    Time time3 = secs_to_time(time_to_secs(time1) + time_to_secs(time2));

    std::cout << "The sum of two time values: " << time3.hours << ':'
              << time3.minutes << ':' << time3.seconds << std::endl;

    return 0;
}

inline long time_to_secs(Time time) {
    return time.hours * 3600 + time.minutes * 60 + time.seconds;
}

Time secs_to_time(long seconds) {
    Time time = { 0, 0, 0 };

    while (seconds >= 3600) {
        seconds -= 3600;
        time.hours++;
    }
    while (seconds >= 60) {
        seconds -= 60;
        time.minutes++;
    }
    time.seconds = seconds;

    if (time.hours > 24)
        time.hours -= 24;

    return time;
}