#include <iostream>

class Date
{
    public :
        Date() : _day(0), _month(0), _year(0)
        { };

        void setDate();
        void showDate() const {
            std::cout << _day << '/' << _month << '/' << _year << std::endl;
        }

    private :
        short _day;
        short _month;
        short _year;
};

void Date::setDate() {
    std::cout << "Enter the required date(in format 31/12/00):\n";
    do {
        std::cout << "...day: ";
        std::cin >> _day;
    } while (_day <= 0 || _day > 31);
    do {
        std::cout << "...month: ";
        std::cin >> _month;
    } while (_month <= 0 || _month > 12);
    do {
        std::cout << "...year: ";
        std::cin >> _year;
    } while (_year < 0 || _year > 99);
}

int main() {
    Date date;
    date.setDate();
    date.showDate();

    return 0;
}