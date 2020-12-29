#include <iostream>

enum Etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

class Date
{
    public :
        Date() : _day(0), _month(0), _year(0) {};
        Date(int d, int m, int y) : _day(d), _month(m), _year(y) {};

        void setDate();
        void showDate() const {
            std::cout << _day << '/' << _month << '/' << _year;
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

class Employee
{
    public :
        Employee() : _empNumber(0), _salary(0.0f), _acceptance(0, 0, 0), _position(laborer) {};
        
        void setData();
        void showData() const;

    private :
        void setDate() { _acceptance.setDate(); }
        void showDate() const { _acceptance.showDate(); }
        void setPosition();
        void showPosition() const;

    private :
        int _empNumber;
        float _salary;
        class Date _acceptance;
        enum Etype _position;
};

void Employee::setPosition() {
    std::cout << "Enter the first letter of the position(l, s, m, a, e, r): ";
    char letter;

    bool isCorrect;
    do {
        isCorrect = true;
        std::cin >> letter;
        switch (letter) {
        case 'l':
            _position = laborer;
            break;
        case 's':
            _position = secretary;
            break;
        case 'm':
            _position = manager;
            break;
        case 'a':
            _position = accountant;
            break;
        case 'e':
            _position = executive;
            break;
        case 'r':
            _position = researcher;
            break;
        default:
            std::cout << "Entered incorrect letter!\n";
            isCorrect = false;
        }
    } while (!isCorrect);
}

void Employee::showPosition() const {
    switch (_position) {
        case laborer :
            std::cout << "laborer";
            break;
        case secretary :
            std::cout << "secretary";
            break;
        case manager :
            std::cout << "manager";
            break;
        case accountant :
            std::cout << "accountant";
            break;
        case executive :
            std::cout << "executive";
            break;
        case researcher :
            std::cout << "researcher";
            break;
    }
}

void Employee::setData() {
    std::cout << "Enter information about employee:\n";
    std::cout << "...number: ";
    std::cin >> _empNumber;
    std::cout << "...salary: ";
    std::cin >> _salary;
    std::cout << "...acceptance date: ";
    setDate();
    std::cout << "...position: ";
    setPosition();
}

void Employee::showData() const {
    std::cout << "Employee number: " << _empNumber
              << ", and his salary - " << _salary
              << ", acceptance date: ";
    showDate();
    std::cout << ", position - ";
    showPosition();
    std::cout << std::endl;
}


int main() {
    std::cout << "Enter number and salary of three different employee...\n";
    Employee empOne;
    empOne.setData();
    Employee empTwo;
    empTwo.setData();
    Employee empThree;
    empThree.setData();

    std::cout << "You entered the following information:\n";
    empOne.showData();
    empTwo.showData();
    empThree.showData();

    return 0;
}