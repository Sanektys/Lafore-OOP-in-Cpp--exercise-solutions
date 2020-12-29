#include <iostream>

class Time
{
    public :
        Time() : _hour(0), _minute(0), _second(0) {};
        Time(int h, int m, int s) : _hour(h), _minute(m), _second(s) {};

        void showTime() const;

        Time operator+(Time timeTwo) const;
        Time operator++() {
            _minute++;
            _validation();
            return Time(_hour, _minute, _second);
        }
        Time operator++(int) {
            Time temp(_hour, _minute, _second);
            _minute++;
            _validation();
            return temp;
        }
        Time operator--() {
            _minute--;
            _validation();
            return Time(_hour, _minute, _second);
        }
        Time operator--(int) {
            Time temp(_hour, _minute, _second);
            _minute--;
            _validation();
            return temp;
        }

    private :
        void _validation();

    private :
        int _hour;
        int _minute;
        int _second;
};

void Time::showTime() const {
    if (_hour < 10)
        std::cout << '0';
    std::cout << _hour << ':';
    if (_minute < 10)
        std::cout << '0';
    std::cout << _minute << ':';
    if (_second < 10)
        std::cout << '0';
    std::cout << _second;
}

void Time::_validation() {
    while (_second >= 60) {
        _minute++;
        _second -= 60;
    }
    while (_minute >= 60) {
        _hour++;
        _minute -= 60;
    }
    while (_hour >= 24)
        _hour -= 24;

    while (_second < 0) {
        _minute--;
        _second += 60;
    }
    while (_minute < 0) {
        _hour--;
        _minute += 60;
    }
    while (_hour < 0)
        _hour += 24;
}

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

    temp._validation();

    return temp;
}

int main() {
    const Time timeOne(12, 8, 30);
    const Time timeTwo(2, 50, 59);

    Time timeThree;
    timeThree = timeOne + timeTwo;
    timeThree.showTime();
    std::cout << std::endl << std::endl;

    Time timeFour = timeThree++;
    timeFour.showTime();
    std::cout << std::endl;
    timeThree.showTime();
    std::cout << std::endl << std::endl;

    timeFour = ++timeThree;
    timeFour.showTime();
    std::cout << std::endl;
    timeThree.showTime();
    std::cout << std::endl << std::endl;

    timeFour = --timeThree;
    timeFour.showTime();
    std::cout << std::endl;
    timeThree.showTime();
    std::cout << std::endl << std::endl;

    timeFour = timeThree--;
    timeFour.showTime();
    std::cout << std::endl;
    timeThree.showTime();
    std::cout << std::endl << std::endl;

    return 0;
}