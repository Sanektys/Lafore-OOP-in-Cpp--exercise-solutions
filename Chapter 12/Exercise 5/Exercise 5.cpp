#include <iostream>

class Time
{
    public :
        Time() : _hour(0), _minute(0), _second(0) {}

        void setTime();
        void getTime() const {
            std::cout << "Time - " << *this << std::endl;
        }

        friend std::ostream& operator<<(std::ostream&, const Time&);

    private :
        short _hour;
        short _minute;
        short _second;
};

void Time::setTime() {
    std::cout << "Enter time in format 23:59:59\n";
    std::cin.unsetf(std::ios::skipws);
    std::cout << "...enter hour: ";   
    while (true) {
        std::cin >> _hour;
        if (!std::cin.good()) {
            std::cout << "Incorrect entered hour! Try again: ";
            std::cin.clear();
            std::cin.ignore(6, '\n');
            continue;
        }
        else if (_hour < 0 || _hour > 23) {
            std::cout << "Entered hour in wrong range! (range from 0 to 23 hours)\n"
                         "Try enter again: ";
            std::cin.ignore(6, '\n');
            continue;
        }
        else {
            std::cin.ignore(6, '\n');
            break;
        }
    }
    std::cout << "...enter minutes: ";
    while (true) {
        std::cin >> _minute;
        if (!std::cin.good()) {
            std::cout << "Incorrect entered minutes! Try again: ";
            std::cin.clear();
            std::cin.ignore(6, '\n');
            continue;
        }
        else if (_minute < 0 || _minute > 59) {
            std::cout << "Entered minutes in wrong range! (range from 0 to 59 minutes)\n"
                         "Try enter again: ";
            std::cin.ignore(6, '\n');
            continue;
        }
        else {
            std::cin.ignore(6, '\n');
            break;
        }
    }
    std::cout << "...enter seconds: ";
    while (true) {
        std::cin >> _second;
        if (!std::cin.good()) {
            std::cout << "Incorrect entered seconds! Try again: ";
            std::cin.clear();
            std::cin.ignore(6, '\n');
            continue;
        }
        else if (_second < 0 || _second > 59) {
            std::cout << "Entered second in wrong range! (range from 0 to 59 second)\n"
                         "Try enter again: ";
            std::cin.ignore(6, '\n');
            continue;
        }
        else {
            std::cin.ignore(6, '\n');
            break;
        }
    }
    std::cin.setf(std::ios::skipws);
}

inline std::ostream& operator<<(std::ostream& out, const Time& time) {
    if (time._hour < 10)
        out << 0 << time._hour;
    else
        out << time._hour;
    out << ':';
    if (time._minute < 10)
        out << 0 << time._minute;
    else
        out << time._minute;
    out << ':';
    if (time._second < 10)
        out << 0 << time._second;
    else
        out << time._second;

    return out;
}

int main() {
    Time time;
    char answer;

    do {
        time.setTime();

        std::cout << "\nYou enter following time - " << time << std::endl;

        std::cin.unsetf(std::ios::skipws);
        while (true) {
            std::cout << "Enter another time(y/n)? ";
            std::cin >> answer;
            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(2, '\n');
                continue;
            }
            else if (answer != 'n' && answer != 'y') {
                std::cin.ignore(2, '\n');
                std::cout << "Enter ONLY \"y\" or \"n\"\n";
                continue;
            }
            else {
                std::cin.ignore(2, '\n');
                break;
            }
        }
        std::cin.setf(std::ios::skipws);
    } while (answer != 'n');

    return 0;
}