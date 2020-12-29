#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>

class Employee
{
    public :
        Employee() : _name("\0"), _number(0) {};

        void setData();
        void showData() const {
            std::cout << "Employee name - " << _name
                      << ", number: " << _number;
        }

    private :
        std::string _name;
        int _number;
};

void Employee::setData() {
    std::cout << "Enter the information about employee:\n";
    std::cout << "...name: ";
    std::cin >> _name;
    std::cout << "...number: ";
    std::cin >> _number;
}

int main() {
    Employee emp[100];

    short count = 0;
    std::cout << "Fill in employee data (up to 100 people)\n";
    do {
        if (count >= 99)
            break;
        std::cout << "Continue(y/n)? ";
        if (_getche() == 'n')
            break;
        std::cout << "\nEmployee " << count + 1 << std::endl;
        emp[count].setData();
        count++;
    } while (true);

    count--;
    std::cout << std::endl;
    while (count >= 0) {
        emp[count].showData();
        std::cout << std::endl;
        count--;
    }

    return 0;
}