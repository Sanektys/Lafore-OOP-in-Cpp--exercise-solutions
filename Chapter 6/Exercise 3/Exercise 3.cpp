#include <iostream>

class Time
{
    public :
        Time() : _hour(0), _minute(0), _second(0) {};
        Time(int h, int m, int s) : _hour(h), _minute(m), _second(s) {};

        void showTime() const {
            std::cout << _hour << ':' << _minute << ':' << _second;
        }

        void addTime(Time timeOne, Time timeTwo);

    private :
        int _hour;
        int _minute;
        int _second;
};

void Time::addTime(Time timeOne, Time timeTwo) {
    int totalSecondOne = timeOne._hour * 3600 + timeOne._minute * 60 + timeOne._second;
    int totalSecondTwo = timeTwo._hour * 3600 + timeTwo._minute * 60 + timeTwo._second;
    int totalSeconds = totalSecondOne + totalSecondTwo;

    while (totalSeconds >= 3600) {
        _hour++;
        totalSeconds -= 3600;
    }

    while (totalSeconds >= 60) {
        _minute++;
        totalSeconds -= 60;
    }

    _second = totalSeconds;
}

int main() {
    const Time timeOne(12, 8, 30);
    const Time timeTwo(2, 40, 59);

    Time timeThree;
    timeThree.addTime(timeOne, timeTwo);
    timeThree.showTime();

    return 0;
}