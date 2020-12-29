#include <iostream>

struct Date
{
    short day;
    short month;
    short year;
};

int main() {
    std::cout << "Enter date in format dd/mm/yyyy: ";
    Date date;
    char slash;
    std::cin >> date.day >> slash >> date.month >> slash >> date.year;

    std::cout << "You entered the following date: "
              << date.day << slash << date.month << slash << date.year << std::endl;

    return 0;
}