#include <iostream>

class Time
{
    public :
        Time() : _hour(0), _minute(0), _second(0) {};
        Time(int h, int m, int s) : _hour(h), _minute(m), _second(s) {};

        void showTime() const {
            std::cout << _hour << ':' << _minute << ':' << _second;
        }

        Time operator+(Time timeTwo) const;

    private :
        int _hour;
        int _minute;
        int _second;
};

Time Time::operator+(Time timeTwo) const {
    int totalSecondOne = _hour * 3600 + _minute * 60 + _second;
    int totalSecondTwo = timeTwo._hour * 3600 + timeTwo._minute * 60 + timeTwo._second;
    int totalSeconds = totalSecondOne + totalSecondTwo;

    Time temp;
    while (totalSeconds >= 3600) {
        temp._hour++;
        totalSeconds -= 3600;
    }

    while (totalSeconds >= 60) {
        temp._minute++;
        totalSeconds -= 60;
    }

    temp._second = totalSeconds;

    return temp;
}

int main() {
    const Time timeOne(12, 8, 30);
    const Time timeTwo(2, 40, 59);

    Time timeThree;
    timeThree = timeOne + timeTwo;
    timeThree.showTime();

    return 0;
}