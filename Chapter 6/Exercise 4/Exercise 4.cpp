#include <iostream>

class Employee
{
    public :
        Employee() : _empNumber(0), _salary(0.0f) {};
        Employee(int num, float sal) : _empNumber(num), _salary(sal) {};

        void setData();
        void showData() {
            std::cout << "Employee number: " << _empNumber
                      << ", and his salary - " << _salary << std::endl;
        }

    private :
        int _empNumber;
        float _salary;
};

void Employee::setData() {
    std::cout << "Enter information about employee:\n";
    std::cout << "Enter employee number: ";
    std::cin >> _empNumber;
    std::cout << "Enter employee salary: ";
    std::cin >> _salary;
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
