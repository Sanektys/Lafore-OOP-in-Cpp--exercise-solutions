#include <iostream>

struct Employee
{
    int employeeNumber;
    float salary;
};

int main() {
    std::cout << "Enter employee number and his salary: ";
    Employee employee1;
    std::cin >> employee1.employeeNumber >> employee1.salary;
    
    std::cout << "Enter employee number and his salary: ";
    Employee employee2;
    std::cin >> employee2.employeeNumber >> employee2.salary;

    std::cout << "Enter employee number and his salary: ";
    Employee employee3;
    std::cin >> employee3.employeeNumber >> employee3.salary;

    std::cout << "Employee: " << "number - " << employee1.employeeNumber
              << " ; salary - " << employee1.salary << std::endl;
    std::cout << "Employee: " << "number - " << employee2.employeeNumber
              << " ; salary - " << employee2.salary << std::endl;
    std::cout << "Employee: " << "number - " << employee3.employeeNumber
              << " ; salary - " << employee3.salary << std::endl;

    return 0;
}