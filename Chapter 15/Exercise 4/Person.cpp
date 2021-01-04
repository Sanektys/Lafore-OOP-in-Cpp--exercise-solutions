#include "Person.h"


void Person::setPerson() {
    std::cout << "Enter first name: ";
    std::cin >> _firstName;
    std::cout << "Enter second name: ";
    std::cin >> _secondName;
    do {
        std::cout << "Enter phone number: ";
        std::cin >> _phoneNumber;
        if (!std::cin.good()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (true);
}


std::istream& operator>>(std::istream& in, Person& pers) {
    pers.display();

    return in;
}

std::istream& operator>>(std::istream& in, Person* pers) {
    pers->display();

    return in;
}