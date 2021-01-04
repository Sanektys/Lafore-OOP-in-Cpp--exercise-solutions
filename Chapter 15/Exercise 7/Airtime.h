#pragma once

#include <iostream>


class Airtime
{
    public :
        Airtime() : _hours(0), _minutes(0) {}
        Airtime(int hour, int minute) : _hours(hour), _minutes(minute) {}

        void display() const;
        void set();

        Airtime operator+(const Airtime&) const;

        bool operator==(const Airtime& airtimeTwo) const {
            return (_hours == airtimeTwo._hours) && (_minutes == airtimeTwo._minutes);
        }

        bool operator<(const Airtime& airtimeTwo) const {
            return (_hours < airtimeTwo._hours) ||
                   (_hours == airtimeTwo._hours && _minutes < airtimeTwo._minutes);
        }

        bool operator!=(const Airtime& airtimeTwo) const {
            return !(*this == airtimeTwo);
        }

        bool operator>(const Airtime& airtimeTwo) const {
            return !(*this < airtimeTwo) && !(*this == airtimeTwo);
        }


    private :
        int _hours;
        int _minutes;
};

